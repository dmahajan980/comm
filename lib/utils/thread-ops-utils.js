// @flow

import {
  type ClientDBThreadInfo,
  type RawThreadInfo,
  assertThreadType,
} from '../types/thread-types';

function convertRawThreadInfoToClientDBThreadInfo(
  rawThreadInfo: RawThreadInfo,
): ClientDBThreadInfo {
  return {
    ...rawThreadInfo,
    creationTime: rawThreadInfo.creationTime.toString(),
    members: JSON.stringify(rawThreadInfo.members),
    roles: JSON.stringify(rawThreadInfo.roles),
    currentUser: JSON.stringify(rawThreadInfo.currentUser),
  };
}

function convertClientDBThreadInfoToRawThreadInfo(
  clientDBThreadInfo: ClientDBThreadInfo,
): RawThreadInfo {
  const { sourceMessageID, ...rawThreadInfo }: RawThreadInfo = {
    ...clientDBThreadInfo,
    type: assertThreadType(clientDBThreadInfo.type),
    creationTime: Number(clientDBThreadInfo.creationTime),
    members: JSON.parse(clientDBThreadInfo.members),
    roles: JSON.parse(clientDBThreadInfo.roles),
    currentUser: JSON.parse(clientDBThreadInfo.currentUser),
  };
  if (clientDBThreadInfo.sourceMessageID) {
    return {
      ...rawThreadInfo,
      sourceMessageID: clientDBThreadInfo.sourceMessageID,
    };
  }
  return rawThreadInfo;
}

export {
  convertRawThreadInfoToClientDBThreadInfo,
  convertClientDBThreadInfoToRawThreadInfo,
};