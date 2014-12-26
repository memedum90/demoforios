#include "../inc/SpDefs.h"
#ifdef DEBUGGER_PLAYER
#ifndef DEBUGGERJSON_H_
#define DEBUGGERJSON_H_

#include <map>
#include <string>
#include <vector>
#include "../jansson/jansson.h"

class DebuggerJson
{
public:
	std::map<std::string,DebuggerJson*> childs;
	std::vector<DebuggerJson*> childs_array;
	char* name;
	char* string_value;
	int int_value;
	bool bool_value;
	double double_value;
	bool string_available;
	bool int_available;
	bool double_available;
	bool bool_available;
	void ParseJsonObject(json_t *node);
	char* method;
	bool valid;
public:
	char* parse_error;
	DebuggerJson();
	~DebuggerJson();
	bool HasJsonChild(const char* name);
	void Parse(const char* data,int len);
	const char* Method();
	bool HasParams();
	bool Valid(){ return valid; }
	DebuggerJson* Params();
	DebuggerJson* GetChild(const char* xpath);
	int Id();

};

#endif
#endif
