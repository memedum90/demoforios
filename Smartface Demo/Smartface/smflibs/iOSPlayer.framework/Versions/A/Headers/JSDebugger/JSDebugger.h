#include "../inc/SpDefs.h"
#ifdef DEBUGGER_PLAYER
//
//  JSDebugger.h
//  JavaScriptCore
//
//  Created by Antti Panula on 5/15/13.
//
//

#ifndef __JavaScriptCore__JSDebugger__
#define __JavaScriptCore__JSDebugger__

#include "JSDebuggerListener.h"
//#include "JSBase.h"

class MobinexDebugger;

class JSDebugger{
public:
    JSDebugger(JSGlobalContextRef ctx, JSDebuggerListener* listener);
    ~JSDebugger();
    
    MobinexDebugger* debugger;
    char* setBreakpoint(const char* sourceID, int reqLineNumber, int reqColumnNumber, char* condition, int* actualLineNumber, int* actualColumnNumber);
    void removeBreakpoint(const char* breakpointId);
    void clearBreakpoints();
    void setBreakpointsActivated(bool activated);
    void activateBreakpoints();
    void deactivateBreakpoints();
    
    enum PauseOnExceptionsState {
        DontPauseOnExceptions,
        PauseOnAllExceptions,
        PauseOnUncaughtExceptions
    };
    
    PauseOnExceptionsState pauseOnExceptionsState() const;
    void setPauseOnExceptionsState(PauseOnExceptionsState);
    
    void setPauseOnNextStatement(bool pause);
    void breakProgram();
    void continueProgram();
    void stepIntoStatement();
    void stepOverStatement();
    void stepOutOfFunction();
    
    enum Type { ProgramType, FunctionType };
    
    void exception(long long callFramePtr, const JSObjectRef& thisObject, const char* exceptionStr, const char* functionName, const char*  sourceID, int lineNumber, int columnNumber, bool hasHandler);
    //void willExecuteProgram(const JSC::DebuggerCallFrame&, intptr_t sourceID, int lineno, int columnNumber);
    //void didExecuteProgram(const JSC::DebuggerCallFrame&, intptr_t sourceID, int lineno, int columnNumber);
    void didReachBreakpoint(long long callFramePtr, const JSObjectRef& thisObject, const char* functionName, const char*  sourceID, int lineno, int columnNumber);
    
    void sourceParsed(const char* sourceUrl, const char* sourceId, int errorLine, const char* errorMessage);

    void didPause(const char* sourceID, int lineNumber, int columnNumber);
    void didContinue();
    
    char* evalC(long long callFrame, char* script);
    JSValueRef eval(long long callFrame, char* script);
    char* dumpScopes(long long cf);
    char* dumpTopStackTrace(long long cf);
    char* dumpStackTrace(long long cf);
    long long getCallerCallFramePtr(long long cf);

private:
    JSDebuggerListener* m_listener;


};


#endif /* defined(__JavaScriptCore__JSDebugger__) */
#endif
