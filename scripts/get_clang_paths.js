// @flow

const clangPaths = [
  {
    path: 'native/cpp/CommonCpp',
    extensions: ['h', 'cpp'],
    excludes: ['_generated'],
  },
  {
    path: 'services/tunnelbroker/contents/server/src',
    extensions: ['cpp', 'h'],
  },
  {
    path: 'services/backup/contents/server/src',
    extensions: ['cpp', 'h'],
  },
  {
    path: 'native/android/app/src/cpp',
    extensions: ['cpp', 'h'],
  },
  {
    path: 'native/ios/Comm',
    extensions: ['h', 'm', 'mm'],
  },
  {
    path: 'native/ios/CommTests',
    extensions: ['mm'],
  },
  {
    path: 'native/android/app/src/main/java/app/comm',
    extensions: ['java'],
    excludes: ['generated'],
  },
];

function getClangPaths() {
  return clangPaths.map(pathItem => pathItem.path);
}

module.exports = { getClangPaths, clangPaths };