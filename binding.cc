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

	void _open_as(const FunctionCallbackInfo<Value>& args) {
        std::string file(*v8::String::Utf8Value(args[0]));
	  	
        std::wstring wfile = std::wstring(file.begin(), file.end());
        OpenAs((wchar_t *) wfile.c_str());
	}

	void _properties(const FunctionCallbackInfo<Value>& args) {
        std::string file(*v8::String::Utf8Value(args[0]));

        std::wstring wfile = std::wstring(file.begin(), file.end());
        Properties((wchar_t *) wfile.c_str());
	}

	void init(Local<Object> exports) {
	  	NODE_SET_METHOD(exports, "openAs", _open_as);
		NODE_SET_METHOD(exports, "properties", _properties);
	}

	NODE_MODULE(addon, init)

}  
