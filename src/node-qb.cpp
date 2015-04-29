#include <node.h>
#include <v8.h>
#include <atlstr.h>

#using <System.dll>
using namespace v8;
#pragma managed
#using <Interop.QBFC13Lib.1.0.dll>

using namespace QBFC13Lib;


void Method(const FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	//convert args to v8 utfvalue. for char* use * as operator
	v8::String::Utf8Value a(args[0]);

	System::String^ applicationName = gcnew System::String(*a);

	QBSessionManager^ sm = gcnew QBSessionManager();
	sm->OpenConnection("test", applicationName);
	sm->BeginSession("", ENOpenMode::omDontCare);
	System::String^ filePath = sm->GetCurrentCompanyFileName();
	CString str(filePath);
	args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, str));
}
#pragma unmanaged
void init(Handle<v8::Object> target) {
	NODE_SET_METHOD(target, "hello", Method);
}

NODE_MODULE(binding, init);