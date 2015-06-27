/* Copyright (C) 2013 Interactive Brokers LLC. All rights reserved. This code is subject to the terms
 * and conditions of the IB API Non-Commercial License or the IB API Commercial License, as applicable. */

#ifndef eposixclientsocketcommon_def
#define eposixclientsocketcommon_def

	// LINUX
	// includes
	#include <arpa/inet.h>
	#include <errno.h>
	#include <sys/select.h>
	#include <sys/fcntl.h>
	#include <unistd.h>
	
	
	// helpers
	inline bool SocketsInit() { return true; };
	inline bool SocketsDestroy() { return true; };
	inline int SocketClose(int sockfd) { return close(sockfd); };

	inline bool SetSocketNonBlocking(int sockfd) { 
		// get socket flags
		int flags = fcntl(sockfd, F_GETFL);
		if (flags == -1)
			return false;

		// set non-blocking mode
		return ( fcntl(sockfd, F_SETFL, flags | O_NONBLOCK) == 0);
	};


#endif
