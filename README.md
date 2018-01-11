# `crypto-stream-xor`

> Streaming symmetric encryption. Unauthenticated! Extension to libsodium

## Usage

```js
var csx = require('crypto-stream-xor')

```

## API

In `libsodium` style this module has a "high-level" API that where an algorithm
with good properties has been picked for you. However, if you need a specific
PRF you can also access the specific algorithm
(`xsalsa20`, `chacha20`, `xchacha20`).

### Default API

#### `csx.crypto_stream_xor_STATEBYTES`
#### `csx.crypto_stream_xor_init`
#### `csx.crypto_stream_xor_update`
#### `csx.crypto_stream_xor_final`

### Specific algorithms

#### `csx.crypto_stream_xsalsa20_xor_STATEBYTES`
#### `csx.crypto_stream_xsalsa20_xor_init()`
#### `csx.crypto_stream_xsalsa20_xor_update()`
#### `csx.crypto_stream_xsalsa20_xor_final()`
#### `csx.crypto_stream_chacha20_xor_STATEBYTES`
#### `csx.crypto_stream_chacha20_xor_init()`
#### `csx.crypto_stream_chacha20_xor_update()`
#### `csx.crypto_stream_chacha20_xor_final()`
#### `csx.crypto_stream_xchacha20_xor_STATEBYTES`
#### `csx.crypto_stream_xchacha20_xor_init()`
#### `csx.crypto_stream_xchacha20_xor_update()`
#### `csx.crypto_stream_xchacha20_xor_final()`

## Install

```sh
npm install crypto-stream-xor
```

## License

[ISC](LICENSE)
