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
	v8::String::Utf8Value appName(args[0]);
	v8::String::Utf8Value query(args[1]);


	System::String^ applicationName = gcnew System::String(*appName);
	System::String^ requestXML = gcnew System::String(*query);


	QBSessionManager^ sm = gcnew QBSessionManager();
	sm->OpenConnection("test", applicationName);
	sm->BeginSession("", ENOpenMode::omDontCare);
	System::String^ filePath = sm->GetCurrentCompanyFileName();
	CString str(filePath);
	
	IMsgSetResponse^ response = sm->DoRequestsFromXMLString(requestXML);
	CString responseXML(response->ToXMLString());
	//args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, responseXML));

	Local<Function> cb = Local<Function>::Cast(args[2]);
 	const unsigned argc = 1;
  	Local<Value> argv[argc] = { v8::String::NewFromUtf8(isolate, responseXML) };
  	cb->Call(isolate->GetCurrentContext()->Global(), argc, argv);
}

#pragma unmanaged
void init(Handle<v8::Object> target) {
	NODE_SET_METHOD(target, "hello", Method);
}

NODE_MODULE(binding, init);