#include "../inc/SpDefs.h"
#ifdef DEBUGGER_PLAYER
#ifndef DEBUGGERSOCKET_H_
#define DEBUGGERSOCKET_H_

#include <string>
#include <vector>

class JSSmartfaceDebugger;

class DebuggerSocket {
private:
	void OpenSocketForClient();
	void OpenSocketForServer();
	bool GetAsServer();
	bool deadSocket;
public:
	char* host;
	int sockfd;
	int serversocketfd;
	int port;
	bool forSending;
    bool closeWithoutDebug;
	JSSmartfaceDebugger* smf_debugger;
	char* buffer;
	pthread_t thread_id;
	bool errorInConnection;
    bool isTimeOut;
	bool workOnUSB;
	const static int WAIT_SECONDS = 60;
public:
	pthread_cond_t cv;
	pthread_mutex_t cvLock;
	bool ForSending() {
		return forSending;
	}
	int GetSockFD(){	return sockfd; }
	int GetServerSocketFD(){	return serversocketfd; }
	void SetServerSocketFD(int fd){	serversocketfd = fd; }
	std::vector<char*> messages_will_be_sent;
	DebuggerSocket(JSSmartfaceDebugger* smf_debugger, bool forSending);
	bool HasErrorInConnection() {
		return errorInConnection || isTimeOut;
	}
    void TimeOut();
    bool HasTimeout() {
        return isTimeOut;
    }
	virtual ~DebuggerSocket();
	//void SetHostAndPort(const char* host, int port);
	void SetHostPortAndWorkOnUSB(const char* host, int port, bool debug);
	void ReceiveData(const char* data);
	const char* GetHost();
	bool IsWorkOnUSB();
	int GetPort();
	void SendData(const char* data);
	void log(const char* msg, const char* msg1 = 0);
	void OpenConnection();
	void OpenSocket();
	void CloseConnection();
	bool IsAlive(){	return !deadSocket; }

	bool IsConnected();
};
#endif
#endif
