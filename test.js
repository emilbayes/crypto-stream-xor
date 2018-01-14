var test = require('test')
var csx = require('../')

test('constants', function (assert) {
  assert.equal(typeof crypto_stream_xor_STATEBYTES, 'number')
  assert.equal(typeof crypto_stream_xor_KEYBYTES, 'number')
  assert.equal(typeof crypto_stream_xor_NONCEBYTES, 'number')
  assert.equal(typeof crypto_stream_xsalsa20_xor_STATEBYTES, 'number')
  assert.equal(typeof crypto_stream_xsalsa20_xor_KEYBYTES, 'number')
  assert.equal(typeof crypto_stream_xsalsa20_xor_NONCEBYTES, 'number')
  assert.equal(typeof crypto_stream_chacha20_xor_STATEBYTES, 'number')
  assert.equal(typeof crypto_stream_chacha20_xor_KEYBYTES, 'number')
  assert.equal(typeof crypto_stream_chacha20_xor_NONCEBYTES, 'number')
  assert.equal(typeof crypto_stream_xchacha20_xor_STATEBYTES, 'number')
  assert.equal(typeof crypto_stream_xchacha20_xor_KEYBYTES, 'number')
  assert.equal(typeof crypto_stream_xchacha20_xor_NONCEBYTES, 'number')
  assert.end()
})





