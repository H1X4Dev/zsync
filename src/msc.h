#pragma once

#ifndef __attribute__
    #ifdef _MSC_VER
        #define __attribute__(x)
    #else
        #define __attribute__(x) __attribute__(x)
    #endif
#endif

#ifdef _MSC_VER
    #include <Windows.h>
typedef SSIZE_T ssize_t;
#else
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <sys/param.h>
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <netdb.h>
#endif

#define HAVE_MEMCPY
#define VERSION "0.7"