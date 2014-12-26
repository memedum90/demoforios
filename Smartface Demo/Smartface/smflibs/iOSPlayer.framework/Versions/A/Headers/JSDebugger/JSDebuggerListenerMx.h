#include "../inc/SpDefs.h"
#ifdef DEBUGGER_PLAYER
#ifndef JavaScriptCore_JSDebuggerListenerMx_h
#define JavaScriptCore_JSDebuggerListenerMx_h

#include <iostream>
#include "JSDebuggerListener.h"
#include "DebuggerSocket.h"

class JSDebuggerListenerMx: public JSDebuggerListener {
public:
    typedef enum {
        KPTBreakpoint,
        KPTException,
        KPTManualPause
    } KPauseType;
private:
	DebuggerSocket* socket;
    JSGlobalContextRef ctx;
	std::string lastBreakSourceID;
	int lastBreakLineNumber;
	int lastBreakColNumber;

public:
	JSSmartfaceDebugger* smf_debugger;
	bool reachBreakPointAfterDidContinue;
	pthread_t operationForDidContinue;
	JSDebuggerListenerMx(DebuggerSocket* socket,JSSmartfaceDebugger* smf_debugger, JSGlobalContextRef _JSContext);

    void exception(long long callFramePtr, const JSObjectRef& thisObject, const char* exceptionStr, const char* functionName, const char* sourceID, int lineNumber, int columnNumber, bool hasHandler);
    void didReachBreakpoint(long long callFramePtr, const JSObjectRef& thisObject, const char* functionName, const char* sourceID, int lineno, int columnNumber);
    void sourceParsed(const char* sourceUrl, const char* sourceId, int errorLine, const char* errorMessage);
    void didPause(const char* sourceID, int lineNumber, int columnNumber);
    void didContinue();

    void sendPausedMessage(long long callFramePtr, KPauseType reason, const void *data);
};


#endif
#endif
