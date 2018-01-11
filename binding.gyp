{
    'variables': {
        'target_arch%': '<!(node -p "os.arch()")>'
    },
    "targets": [
    {
        "target_name": "crypto-stream-xor",
        "sources": [
            "index.cc",
            "crypto-stream-state/src/crypto_stream_xor.c",
            "crypto-stream-state/src/crypto_stream_xsalsa20_xor.c",
            "crypto-stream-state/src/crypto_stream_chacha20_xor.c",
            "crypto-stream-state/src/crypto_stream_xchacha20_xor.c",
        ],
        "include_dirs": [
            "<!(node -e \"require('nan')\")",
            "<!(node -p \"require('libsodium-prebuilt/include')\")",
            "<!(pwd)/crypto-stream-state/src/",
        ],
        'xcode_settings': {
            'OTHER_CFLAGS': [
                '-g',
                '-O3'
            ]
        },
        'cflags': [
            '-g',
            '-O3'
        ],
    }
  ]
}
