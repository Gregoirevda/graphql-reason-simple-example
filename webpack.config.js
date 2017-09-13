const path = require('path');

module.exports = {
  entry: {
    simple: './lib/js/src/simple/Root.js',
  },
  output: {
    path: path.join(__dirname, "bundledOutputs"),
    filename: '[name].js',
  },
};
