var s = require('.')

var state = Buffer.alloc(s.crypto_stream_xor_STATEBYTES)
var key = Buffer.alloc(32).fill('hello world')
var nonce = Buffer.alloc(24).fill('hi verden')

var plain1 = Buffer.alloc(32).fill('emil er sej')
var cipher = Buffer.alloc(32)
var plain2 = Buffer.alloc(32)

s.crypto_stream_xor_init(state, key, nonce)
var state2 = Buffer.alloc(state.length).fill(state)

s.crypto_stream_xor_update(state, cipher, plain1)

s.crypto_stream_xor_update(state2, plain2, cipher)

process.exit(plain1.compare(plain2))
