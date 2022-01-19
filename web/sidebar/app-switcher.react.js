// @flow

import invariant from 'invariant';
import * as React from 'react';
import { useDispatch } from 'react-redux';

import {
  mostRecentReadThreadSelector,
  unreadCount,
} from 'lib/selectors/thread-selectors';

import { useSelector } from '../redux/redux-utils';
import getTitle from '../title/getTitle';
import { updateNavInfoActionType } from '../types/nav-types';
import css from './sidebar.css';

function AppSwitcher(): React.Node {
  const activeChatThreadID = useSelector(
    state => state.navInfo.activeChatThreadID,
  );
  const navInfo = useSelector(state => state.navInfo);
  const mostRecentReadThread = useSelector(mostRecentReadThreadSelector);
  const activeThreadCurrentlyUnread = useSelector(
    state =>
      !activeChatThreadID ||
      !!state.threadStore.threadInfos[activeChatThreadID]?.currentUser.unread,
  );
  const viewerID = useSelector(
    state => state.currentUserInfo && state.currentUserInfo.id,
  );

  const boundUnreadCount = useSelector(unreadCount);

  React.useEffect(() => {
    document.title = getTitle(boundUnreadCount);
  }, [boundUnreadCount]);

  const dispatch = useDispatch();

  const onClickCalendar = React.useCallback(
    (event: SyntheticEvent<HTMLAnchorElement>) => {
      event.preventDefault();
      dispatch({
        type: updateNavInfoActionType,
        payload: { tab: 'calendar' },
      });
    },
    [dispatch],
  );

  const onClickChat = React.useCallback(
    (event: SyntheticEvent<HTMLAnchorElement>) => {
      event.preventDefault();
      dispatch({
        type: updateNavInfoActionType,
        payload: {
          tab: 'chat',
          activeChatThreadID: activeThreadCurrentlyUnread
            ? mostRecentReadThread
            : navInfo.activeChatThreadID,
        },
      });
    },
    [
      dispatch,
      activeThreadCurrentlyUnread,
      mostRecentReadThread,
      navInfo.activeChatThreadID,
    ],
  );

  invariant(viewerID, 'should be set');
  let chatBadge = null;
  if (boundUnreadCount > 0) {
    chatBadge = <div className={css.chatBadge}>{boundUnreadCount}</div>;
  }

  return (
    <div className={css.container}>
      <ul>
        <li>
          <p>
            <a onClick={onClickCalendar}>Calendar</a>
          </p>
        </li>
        <li>
          <p>
            <a onClick={onClickChat}>Chat</a>
            {chatBadge}
          </p>
        </li>
      </ul>
    </div>
  );
}

export default AppSwitcher;
