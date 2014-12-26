#include "../inc/SpDefs.h"
#ifdef DEBUGGER_PLAYER
//
//  JSDebuggerListener.h
//  JavaScriptCore
//
//  Created by Antti Panula on 5/16/13.
//
//

#ifndef JavaScriptCore_JSDebuggerListener_h
#define JavaScriptCore_JSDebuggerListener_h

#include "../JavaScriptCore/inc/JSBase.h"

class JSDebuggerListener{
public:
    virtual void exception(long long callFramePtr, const JSObjectRef& thisObject, const char* exceptionStr, const char* functionName, const char* sourceID, int lineNumber, int columnNumber, bool hasHandler) = 0;
    virtual void didReachBreakpoint(long long callFramePtr, const JSObjectRef& thisObject, const char* functionName, const char* sourceID, int lineno, int columnNumber) = 0;
    virtual void sourceParsed(const char* sourceUrl, const char* sourceId, int errorLine, const char* errorMessage) = 0;
    virtual void didPause(const char* sourceID, int lineNumber, int columnNumber) = 0;
    virtual void didContinue() = 0;
};


#endif
#endif
