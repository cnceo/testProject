/*
 * define file about portable socket class. 
 * description:this sock is suit both windows and linux
 * design:odison
 * e-mail:odison@126.com>
 * 
 */

#ifndef _ODSOCKET_H_
#define _ODSOCKET_H_

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include "errno.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
typedef int				SOCKET;

//#pragma region define win32 const variable in linux
#define INVALID_SOCKET	-1
#define SOCKET_ERROR	-1
//#pragma endregion


class ODSocket {

public:
	ODSocket(SOCKET sock = INVALID_SOCKET);
	~ODSocket();

	// Create socket object for snd/recv data
	bool Create();
    
    bool CreateServer();

	// Connect socket
	bool Connect(const char* ip, unsigned short port);
	//#region server
	// Bind socket
	bool Bind(unsigned short port);

	// Listen socket
	bool Listen(int backlog = 5); 

	// Accept socket
	bool Accept(ODSocket& s, char* fromip = NULL);
	//#endregion
	
	// Send socket
	int Send(const char* buf, int len, int flags = 0);
    
	// SendTo socket
	int Sendto(const char* buf,int len,const struct sockaddr * to, int tolen,int flags=0);
    
    // send udp broadcast
    int Send_broadcast(const char* buf,int len,unsigned short port);
    
#if(CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
	int Recvfrom(char* buf,int len, struct sockaddr * to, unsigned int tolen,int flags=0);
#else
    int Recvfrom(char* buf,int len, struct sockaddr * to, int tolen,int flags=0);
#endif
    
	// Recv socket
	int Recv(char* buf, int len, int flags = 0);

	int Setsockopt();
	int SetsockoptUdp();

	// Close socket
	int Close();

	// Get errno
	int GetError();
	
	//#pragma region just for win32
	// Init winsock DLL 
	static int Init();	
	// Clean winsock DLL
	static int Clean();
	//#pragma endregion

	// Domain parse
	static bool DnsParse(const char* domain, char* ip);

	ODSocket& operator = (SOCKET s);

	operator SOCKET ();

protected:
	SOCKET m_sock;

};

#endif
