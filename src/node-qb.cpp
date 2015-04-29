#include <node.h>
#include <v8.h>

#using <System.dll>
using namespace v8;
#pragma managed
#using <Interop.QBFC13Lib.1.0.dll>

using namespace QBFC13Lib;

void Method(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);
	args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "world"));
	QBSessionManager^ sm = gcnew QBSessionManager();
	sm->OpenConnection("test", "TZ");
	sm->BeginSession("", ENOpenMode::omDontCare);
}
#pragma unmanaged
void init(Handle<v8::Object> target) {
	NODE_SET_METHOD(target, "hello", Method);
}

NODE_MODULE(binding, init);