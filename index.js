require('libsodium-prebuilt') // makes sure libsodium shared library is loaded
var binding = require('node-gyp-build')(__dirname)

module.exports = binding
