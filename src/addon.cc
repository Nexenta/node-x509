#include <cstdlib>
#include <cstdio>

#include <addon.h>
#include <x509.h>

using namespace v8;

inline v8::Isolate *isol() {
    return v8::Isolate::GetCurrent();
}

inline v8::Local<v8::Context> ctx() {
    return v8::Isolate::GetCurrent()->GetCurrentContext();
}

void init(Local<Object> exports) {
  Nan::Set(exports,
    Nan::New<String>("version").ToLocalChecked(),
    Nan::New<String>(VERSION).ToLocalChecked());

  Nan::Set(exports,
    Nan::New<String>("verify").ToLocalChecked(),
    Nan::New<FunctionTemplate>(verify)->GetFunction(ctx()).ToLocalChecked());

  Nan::Set(exports,
    Nan::New<String>("getAltNames").ToLocalChecked(),
    Nan::New<FunctionTemplate>(get_altnames)->GetFunction(ctx()).ToLocalChecked());
  Nan::Set(exports,
    Nan::New<String>("getSubject").ToLocalChecked(),
    Nan::New<FunctionTemplate>(get_subject)->GetFunction(ctx()).ToLocalChecked());
  Nan::Set(exports,
    Nan::New<String>("getIssuer").ToLocalChecked(),
    Nan::New<FunctionTemplate>(get_issuer)->GetFunction(ctx()).ToLocalChecked());
  Nan::Set(exports,
    Nan::New<String>("parseCert").ToLocalChecked(),
    Nan::New<FunctionTemplate>(parse_cert)->GetFunction(ctx()).ToLocalChecked());
}

NODE_MODULE(x509, init)
