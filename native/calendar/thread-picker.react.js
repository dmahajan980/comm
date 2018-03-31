// @flow

import type { AppState } from '../redux-setup';
import type { ThreadInfo } from 'lib/types/thread-types';
import { threadInfoPropType } from 'lib/types/thread-types';
import type { DispatchActionPayload } from 'lib/utils/action-utils';

import React from 'react';
import PropTypes from 'prop-types';
import { View, Text, StyleSheet } from 'react-native';
import { connect } from 'react-redux';
import invariant from 'invariant';

import {
  onScreenEntryEditableThreadInfos,
} from 'lib/selectors/thread-selectors';
import {
  createLocalEntry,
  createLocalEntryActionType,
} from 'lib/actions/entry-actions';
import { includeDispatchActionProps } from 'lib/utils/action-utils';
import { threadSearchIndex } from 'lib/selectors/nav-selectors';
import SearchIndex from 'lib/shared/search-index';

import ThreadList from '../components/thread-list.react';
import KeyboardAvoidingModal from '../components/keyboard-avoiding-modal.react';

type Props = {
  dateString: ?string,
  close: () => void,
  // Redux state
  onScreenThreadInfos: $ReadOnlyArray<ThreadInfo>,
  viewerID: string,
  threadSearchIndex: SearchIndex,
  // Redux dispatch functions
  dispatchActionPayload: DispatchActionPayload,
};
class ThreadPicker extends React.PureComponent<Props> {

  static propTypes = {
    dateString: PropTypes.string,
    close: PropTypes.func.isRequired,
    onScreenThreadInfos: PropTypes.arrayOf(threadInfoPropType).isRequired,
    viewerID: PropTypes.string.isRequired,
    threadSearchIndex: PropTypes.instanceOf(SearchIndex).isRequired,
    dispatchActionPayload: PropTypes.func.isRequired,
  };

  render() {
    return (
      <KeyboardAvoidingModal
        containerStyle={styles.container}
        style={styles.container}
      >
        <ThreadList
          threadInfos={this.props.onScreenThreadInfos}
          onSelect={this.threadPicked}
          itemStyle={styles.threadListItem}
          searchIndex={this.props.threadSearchIndex}
        />
      </KeyboardAvoidingModal>
    );
  }

  threadPicked = (threadID: string) => {
    this.props.close();
    const dateString = this.props.dateString;
    invariant(dateString, "should be set");
    this.props.dispatchActionPayload(
      createLocalEntryActionType,
      createLocalEntry(threadID, dateString, this.props.viewerID),
    );
  }

}

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  headerText: {
    fontSize: 24,
    textAlign: 'center',
    color: "black",
    paddingBottom: 8,
  },
  threadListItem: {
    paddingVertical: 2,
    paddingLeft: 10,
    paddingRight: 10,
  },
});

export default connect(
  (state: AppState) => {
    const viewerID = state.currentUserInfo && state.currentUserInfo.id;
    invariant(viewerID, "should have viewer ID in to use ThreadPicker");
    return {
      onScreenThreadInfos: onScreenEntryEditableThreadInfos(state),
      viewerID,
      threadSearchIndex: threadSearchIndex(state),
    };
  },
  includeDispatchActionProps,
)(ThreadPicker);
