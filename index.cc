#include <nan.h>
#include <sodium.h>
#include <crypto_stream_xor.h>
#include <crypto_stream_xsalsa20_xor.h>
#include <crypto_stream_chacha20_xor.h>
#include <crypto_stream_xchacha20_xor.h>

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define CDATA(buf) (unsigned char *) node::Buffer::Data(buf)
#define CLENGTH(buf) (unsigned long long) node::Buffer::Length(buf)
#define LOCAL_STRING(str) Nan::New<v8::String>(str).ToLocalChecked()
#define LOCAL_FUNCTION(fn) Nan::GetFunction(Nan::New<v8::FunctionTemplate>(fn)).ToLocalChecked()
#define EXPORT_NUMBER(name) Nan::Set(target, LOCAL_STRING(#name), Nan::New<v8::Number>(name));
#define EXPORT_NUMBER_VALUE(name, value) Nan::Set(target, LOCAL_STRING(#name), Nan::New<v8::Number>(value));
#define EXPORT_STRING(name) Nan::Set(target, LOCAL_STRING(#name), LOCAL_STRING(name));
#define EXPORT_FUNCTION(name) Nan::Set(target, LOCAL_STRING(#name), LOCAL_FUNCTION(name));

#define ERRNO_EXCEPTION(errorno) \
  Nan::ErrnoException(errorno, NULL, strerror(errorno))

#define CALL_SODIUM(fn) \
  int ret = fn; \
  if (ret) { \
    Nan::ThrowError(ERRNO_EXCEPTION(errno)); \
    return; \
  }

#define ASSERT_BUFFER(name, var) \
  if (!name->IsObject()) { \
    Nan::ThrowError(#var " must be a buffer"); \
    return; \
  } \
  v8::Local<v8::Object> var = name->ToObject();

#define ASSERT_BUFFER_SET_LENGTH(name, var) \
  ASSERT_BUFFER(name, var) \
  unsigned long long var##_length = CLENGTH(var);

#define ASSERT_BUFFER_MIN_LENGTH(name, var, length) \
  ASSERT_BUFFER_SET_LENGTH(name, var) \
  if (length > 0 && var##_length < length) { \
    Nan::ThrowError(#var " must be a buffer of size " STR(length)); \
    return; \
  }

#define ASSERT_BUFFER_CAST(name, var, type, length) \
  ASSERT_BUFFER_MIN_LENGTH(name, var##_buf, length) \
  type *var = (type *) node::Buffer::Data(var##_buf);

// default

NAN_METHOD(crypto_stream_xor_init) {
  ASSERT_BUFFER_CAST(info[0], state_ptr, crypto_stream_xor_state, crypto_stream_xor_statebytes())
  ASSERT_BUFFER(info[1], key)
  ASSERT_BUFFER(info[2], nonce)

  CALL_SODIUM(crypto_stream_xor_init(state_ptr, CDATA(key), CDATA(nonce)))
}

NAN_METHOD(crypto_stream_xor_update) {
  ASSERT_BUFFER_CAST(info[0], state_ptr, crypto_stream_xor_state, crypto_stream_xor_statebytes())
  ASSERT_BUFFER_SET_LENGTH(info[2], input)
  ASSERT_BUFFER_MIN_LENGTH(info[1], output, input_length)

  CALL_SODIUM(crypto_stream_xor_update(state_ptr, CDATA(output), CDATA(input), input_length))
}

NAN_METHOD(crypto_stream_xor_final) {
  ASSERT_BUFFER_CAST(info[0], state_ptr, crypto_stream_xor_state, crypto_stream_xor_statebytes())

  CALL_SODIUM(crypto_stream_xor_final(state_ptr))
}

// xsalsa20

NAN_METHOD(crypto_stream_xsalsa20_xor_init) {
  ASSERT_BUFFER_CAST(info[0], state_ptr, crypto_stream_xsalsa20_xor_state, crypto_stream_xsalsa20_xor_statebytes())
  ASSERT_BUFFER(info[1], key)
  ASSERT_BUFFER(info[2], nonce)

  CALL_SODIUM(crypto_stream_xsalsa20_xor_init(state_ptr, CDATA(key), CDATA(nonce)))
}

NAN_METHOD(crypto_stream_xsalsa20_xor_update) {
  ASSERT_BUFFER_CAST(info[0], state_ptr, crypto_stream_xsalsa20_xor_state, crypto_stream_xsalsa20_xor_statebytes())
  ASSERT_BUFFER_SET_LENGTH(info[2], input)
  ASSERT_BUFFER_MIN_LENGTH(info[1], output, input_length)

  CALL_SODIUM(crypto_stream_xsalsa20_xor_update(state_ptr, CDATA(output), CDATA(input), input_length))
}

NAN_METHOD(crypto_stream_xsalsa20_xor_final) {
  ASSERT_BUFFER_CAST(info[0], state_ptr, crypto_stream_xsalsa20_xor_state, crypto_stream_xsalsa20_xor_statebytes())

  CALL_SODIUM(crypto_stream_xsalsa20_xor_final(state_ptr))
}

// chacha20

NAN_METHOD(crypto_stream_chacha20_xor_init) {
  ASSERT_BUFFER_CAST(info[0], state_ptr, crypto_stream_chacha20_xor_state, crypto_stream_chacha20_xor_statebytes())
  ASSERT_BUFFER(info[1], key)
  ASSERT_BUFFER(info[2], nonce)

  CALL_SODIUM(crypto_stream_chacha20_xor_init(state_ptr, CDATA(key), CDATA(nonce)))
}

NAN_METHOD(crypto_stream_chacha20_xor_update) {
  ASSERT_BUFFER_CAST(info[0], state_ptr, crypto_stream_chacha20_xor_state, crypto_stream_chacha20_xor_statebytes())
  ASSERT_BUFFER_SET_LENGTH(info[2], input)
  ASSERT_BUFFER_MIN_LENGTH(info[1], output, input_length)

  CALL_SODIUM(crypto_stream_chacha20_xor_update(state_ptr, CDATA(output), CDATA(input), input_length))
}

NAN_METHOD(crypto_stream_chacha20_xor_final) {
  ASSERT_BUFFER_CAST(info[0], state_ptr, crypto_stream_chacha20_xor_state, crypto_stream_chacha20_xor_statebytes())

  CALL_SODIUM(crypto_stream_chacha20_xor_final(state_ptr))
}

// xchacha20

NAN_METHOD(crypto_stream_xchacha20_xor_init) {
  ASSERT_BUFFER_CAST(info[0], state_ptr, crypto_stream_xchacha20_xor_state, crypto_stream_xchacha20_xor_statebytes())
  ASSERT_BUFFER(info[1], key)
  ASSERT_BUFFER(info[2], nonce)

  CALL_SODIUM(crypto_stream_xchacha20_xor_init(state_ptr, CDATA(key), CDATA(nonce)))
}

NAN_METHOD(crypto_stream_xchacha20_xor_update) {
  ASSERT_BUFFER_CAST(info[0], state_ptr, crypto_stream_xchacha20_xor_state, crypto_stream_xchacha20_xor_statebytes())
  ASSERT_BUFFER_SET_LENGTH(info[2], input)
  ASSERT_BUFFER_MIN_LENGTH(info[1], output, input_length)

  CALL_SODIUM(crypto_stream_xchacha20_xor_update(state_ptr, CDATA(output), CDATA(input), input_length))
}

NAN_METHOD(crypto_stream_xchacha20_xor_final) {
  ASSERT_BUFFER_CAST(info[0], state_ptr, crypto_stream_xchacha20_xor_state, crypto_stream_xchacha20_xor_statebytes())

  CALL_SODIUM(crypto_stream_xchacha20_xor_final(state_ptr))
}

NAN_MODULE_INIT(InitAll) {
  if (sodium_init() == -1) {
    Nan::ThrowError("sodium_init() failed");
    return;
  }

  EXPORT_NUMBER_VALUE(crypto_stream_xor_STATEBYTES, crypto_stream_xor_statebytes())
  EXPORT_NUMBER_VALUE(crypto_stream_xor_KEYBYTES, crypto_stream_keybytes())
  EXPORT_NUMBER_VALUE(crypto_stream_xor_NONCEBYTES, crypto_stream_noncebytes())
  EXPORT_FUNCTION(crypto_stream_xor_init)
  EXPORT_FUNCTION(crypto_stream_xor_update)
  EXPORT_FUNCTION(crypto_stream_xor_final)

  EXPORT_NUMBER_VALUE(crypto_stream_xsalsa20_xor_STATEBYTES, crypto_stream_xsalsa20_xor_statebytes())
  EXPORT_NUMBER_VALUE(crypto_stream_xsalsa20_xor_KEYBYTES, crypto_stream_xsalsa20_keybytes())
  EXPORT_NUMBER_VALUE(crypto_stream_xsalsa20_xor_NONCEBYTES, crypto_stream_xsalsa20_noncebytes())
  EXPORT_FUNCTION(crypto_stream_xsalsa20_xor_init)
  EXPORT_FUNCTION(crypto_stream_xsalsa20_xor_update)
  EXPORT_FUNCTION(crypto_stream_xsalsa20_xor_final)

  EXPORT_NUMBER_VALUE(crypto_stream_chacha20_xor_STATEBYTES, crypto_stream_chacha20_xor_statebytes())
  EXPORT_NUMBER_VALUE(crypto_stream_chacha20_xor_KEYBYTES, crypto_stream_chacha20_keybytes())
  EXPORT_NUMBER_VALUE(crypto_stream_chacha20_xor_NONCEBYTES, crypto_stream_chacha20_noncebytes())
  EXPORT_FUNCTION(crypto_stream_chacha20_xor_init)
  EXPORT_FUNCTION(crypto_stream_chacha20_xor_update)
  EXPORT_FUNCTION(crypto_stream_chacha20_xor_final)

  EXPORT_NUMBER_VALUE(crypto_stream_xchacha20_xor_STATEBYTES, crypto_stream_xchacha20_xor_statebytes())
  EXPORT_NUMBER_VALUE(crypto_stream_xchacha20_xor_KEYBYTES, crypto_stream_xchacha20_keybytes())
  EXPORT_NUMBER_VALUE(crypto_stream_xchacha20_xor_NONCEBYTES, crypto_stream_xchacha20_noncebytes())
  EXPORT_FUNCTION(crypto_stream_xchacha20_xor_init)
  EXPORT_FUNCTION(crypto_stream_xchacha20_xor_update)
  EXPORT_FUNCTION(crypto_stream_xchacha20_xor_final)
}

NODE_MODULE(CryptoStreamXor, InitAll)
