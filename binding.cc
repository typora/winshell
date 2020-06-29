#include <node.h>
#include <string>
#include "src/ShellExecuteEx.h"

namespace winshell {

	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;
	
	wchar_t* toWChar(const char* utf8)
	{
		int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
		wchar_t* wstr = new wchar_t[len+1];
		memset(wstr, 0, len+1);
		MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
		return wstr;
	}

	void _open_as(const FunctionCallbackInfo<Value>& args) {
		// from v8 to cpp
		v8::Isolate* isolate = args.GetIsolate();
		v8::String::Utf8Value str(isolate, args[0]);
        	std::string file(*str);
        	OpenAs(toWChar(file.c_str()));
	}

	void _properties(const FunctionCallbackInfo<Value>& args) {
        	v8::Isolate* isolate = args.GetIsolate();
		v8::String::Utf8Value str(isolate, args[0]);
        	std::string file(*str);
        	Properties(toWChar(file.c_str()));
	}
	
	NAN_MODULE_INIT(init) {
	  Nan::SetMethod(target, "openAs", _open_as);
	  Nan::SetMethod(target, "properties", _properties);
	}
	
	#if NODE_MAJOR_VERSION >= 10
	NAN_MODULE_WORKER_ENABLED(addon, init)
	#else
	NODE_MODULE(addon, init)
	#endif
}
