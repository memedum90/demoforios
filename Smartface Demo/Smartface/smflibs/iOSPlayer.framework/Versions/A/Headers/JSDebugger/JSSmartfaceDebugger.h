#include "../inc/SpDefs.h"
#ifdef DEBUGGER_PLAYER
#ifndef JSDEBUGGER_H_
#define JSDEBUGGER_H_

#define SpDebuggerWaitingMessage "Waiting for Connection..."

#include <map>
#include <vector>
#include <string>
#include "DebuggerJson.h"
#include "DebuggerBreakpoint.h"
#include "DebuggerSocket.h"
#include "JSDebugger.h"
#include "JSDebuggerListenerMx.h"
#include "../inc/SpBrBase.h"

class JSSmartfaceDebugger;

typedef enum {
	DOTNone,
	DOTStepOver,
	DOTStepInto,
	DOTStepOut,
} DebugOperationType  ;
struct ScriptBreakpoint
{
	int lineNumber;
	int columnNumber;
};

struct ScriptRuntimeEvaluateCommand {
	char* expression;
	int message_id;
	SpBrBase* baseData;
	JSGlobalContextRef JSContext;
	JSSmartfaceDebugger* smf_debugger;
};

class JSSmartfaceDebugger
{
private:

	static JSSmartfaceDebugger* instance;
	JSDebugger* jscore_debugger;
	JSDebuggerListenerMx* jscore_debugger_listener;
	std::map<std::string,std::string> sourceUrls;
	std::map<std::string,std::string> sourceIds;
	std::map<std::string,std::vector<DebuggerBreakpoint*> > breakpoints;
	bool debugging_lines;
	bool exception_handling;
    bool manual_pause;
	long long debugging_last_callframeptr;
	long long debugging_breakpoint_callframeptr;
	DebugOperationType lastBreakOp;
	int connectedSockets;
	int errorInConnections;
	int errorInLateConnections;
	SpBrBase* baseData;
	SpEventGroup *debuggerAlertDialogEvent;

	std::string param_host;
	std::string param_port1;
	std::string param_port2;
	std::string param_debug;
    std::string device_propery_string;
	JSGlobalContextRef JSContext;
	int serverSocketForSending;
	int serverSocketForListening;
	int json_id_counter;
	bool logEnabled;
	pthread_t safeThread;
    pthread_mutex_t dialogMutex;
    SpApplication* mainApp;
    bool send_variables_on_pause;
    bool reachedGlobal;
public:
	DebuggerSocket* socket_for_listening;
	DebuggerSocket* socket_for_sending;
    
    pthread_cond_t timeoutCondition;
    pthread_mutex_t timeoutLock;
public:
	JSSmartfaceDebugger();
	~JSSmartfaceDebugger();
	static JSSmartfaceDebugger* GetInstance();
	static bool InstanceAlive();
	void Start(std::map<std::string,std::string> params,JSGlobalContextRef _JSContext, SpBrBase* base, SpApplication* mainApp);
	void Restart();
	bool IsRestartable();
    bool IsConnected();
	int GetNewJsonID();
	void ExecutionCompleted();
	bool IsSendLogEnabled();
	bool IsSendingVariablesOnPause();
	void SetLastDebugOperation(DebugOperationType type);
	void SetLastCallframeptr(long long callframeptr);
	DebugOperationType GetLastDebugOperation();
	char* ReceiveCommand(DebuggerSocket* socket, const char* received);
	void SendLogJson(const char* log);
	void SendStopMessage();
	void PutSource(std::string sourceId,std::string sourceUrl);
	void PutBreakpoint(DebuggerBreakpoint* p);
	void RemoveBreakpoint(const char* breakpointId);
	bool HasBreakpointInLine(std::string &scriptId, int linenum,int colnum,long long callframeptr);
	std::string GetSourceUrl(std::string &sourceId);
	std::string GetSourceId(std::string &sourceUrl);
	JSDebugger* GetJscoreDebugger();
	bool IsDebuggingLines(long long callFramePtr);
	void SetDebuggingLines(bool b);
    void SetManualPaused(bool value);
    bool IsManualPaused();
	void SetExceptionHandling(bool b);
	void SocketConnected(DebuggerSocket* socket);
    void SocketTimeout();
	bool HasErrorInConnections();
	void SetConnectionError();
	pthread_t GetSafeThread();
    void HasReachedGlobalJS();
    bool ReachedGlobalJS();

	void SetLateConnectionError(DebuggerSocket* which);
	static bool ParseVariableType(const char* line, std::string &varType,std::string &varSubtype,std::string &varClass,std::string &varValue,std::vector<std::string> &objectProperties);
	static bool FillVariableType(JSGlobalContextRef JSContext,JSValueRef value, std::string &varType,std::string &varSubtype,std::string &varClass,std::string &varValue,bool fillContentIfFunction);
};


#endif
#endif
