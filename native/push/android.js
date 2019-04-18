// @flow

import type { Dispatch } from 'lib/types/redux-types';
import type { RemoteMessage } from 'react-native-firebase';

import firebase from 'react-native-firebase';
import invariant from 'invariant';

import { recordAndroidNotificationActionType } from '../redux/action-types';

import { saveMessageInfos } from './utils';
import { store } from '../redux/redux-setup';

const androidNotificationChannelID = 'default';

type Texts = {|
  title: string,
  prefix: string,
  body: string,
|};
function handleAndroidMessage(
  message: RemoteMessage,
  dispatch: Dispatch,
  updatesCurrentAsOf: number,
  handleIfActive?: (
    threadID: string,
    texts: {| body: string, title: ?string |},
  ) => bool,
) {
  const { data } = message;
  const { badge } = data;
  if (badge !== undefined && badge !== null) {
    firebase.notifications().setBadge(parseInt(badge));
  }

  const customNotification = data.custom_notification
    ? JSON.parse(data.custom_notification)
    : null;
  let { messageInfos } = data;
  if (!messageInfos && customNotification) {
    messageInfos = customNotification.messageInfos;
  }
  if (messageInfos) {
    saveMessageInfos(dispatch, messageInfos, updatesCurrentAsOf);
  }

  let { rescind, rescindID } = data;
  if (!rescind && customNotification) {
    ({ rescind, notifID: rescindID } = customNotification);
  }
  if (rescind) {
    invariant(rescindID, "rescind message without notifID");
    firebase.notifications().removeDeliveredNotification(rescindID);
    //TODO remove from Redux as well
    return;
  }

  let { id, title, prefix, body, threadID } = data;
  if (!id && customNotification) {
    ({ id, body, threadID } = customNotification);
  }
  const merged = prefix ? `${prefix} ${body}` : body;

  if (handleIfActive) {
    const texts = { title, body: merged };
    const isActive = handleIfActive(threadID, texts);
    if (isActive) {
      return;
    }
  }

  const notification = new firebase.notifications.Notification()
    .setNotificationId(id)
    .setBody(merged)
    .setData({ threadID })
    .android.setChannelId(androidNotificationChannelID)
    .android.setDefaults(firebase.notifications.Android.Defaults.All)
    .android.setVibrate(true)
    .android.setAutoCancel(true)
    .android.setLargeIcon("@mipmap/ic_launcher")
    .android.setSmallIcon("@drawable/notif_icon");
  if (title) {
    notification.setTitle(title);
  }
  firebase.notifications().displayNotification(notification);

  // We keep track of what notifs have been rendered for a given thread so
  // that we can clear them immediately (without waiting for the rescind)
  // when the user navigates to that thread. Since we can't do this while
  // the app is closed, we rely on the rescind notif in that case.
  dispatch({
    type: recordAndroidNotificationActionType,
    payload: { threadID, notifID: id },
  });
}

async function androidBackgroundMessageTask(message: RemoteMessage) {
  const { dispatch } = store;
  const { updatesCurrentAsOf } = store.getState();
  handleAndroidMessage(message, dispatch, updatesCurrentAsOf);
}

export {
  androidNotificationChannelID,
  handleAndroidMessage,
  androidBackgroundMessageTask,
};
