#include "../inc/SpDefs.h"
#ifdef DEBUGGER_PLAYER
#ifndef DEBUGGERBREAKPOINT_H_
#define DEBUGGERBREAKPOINT_H_

#include <map>
#include <string>
#include <vector>
#include "../jansson/jansson.h"
#include "../JavaScriptCore/inc/JavaScriptCore.h"

class DebuggerBreakpoint
{

public:
	int linenum;
	int colnum;
	int actlinenum;
	int actcolnum;
	std::string scriptUrl;
	bool active;
	std::string breakpointId;
	std::string condition;
	bool condition_available;
public:
	DebuggerBreakpoint();
	~DebuggerBreakpoint();
};

#endif
#endif

