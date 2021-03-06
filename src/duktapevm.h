#pragma once

#include "callback.h"

#include <duktape.h>

#include <string>

namespace duktape {

struct Result
{
	Result(): errorCode(0) {}
	int errorCode;
	std::string value;
};

class DuktapeVM
{
public:
	DuktapeVM();
	~DuktapeVM();

	Result run(const std::string& scriptName, const std::string& parameter, const std::string& script);
	void registerCallback(const std::string& functionName, Callback callback);

private:
	duk_context* m_ctx;
};

}  // namespace duktape
