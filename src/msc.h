#pragma once

#ifndef __attribute__
    #ifdef _MSC_VER
        #define __attribute__(x)
    #else
        #define __attribute__(x) __attribute__(x)
    #endif
#endif

#ifdef _MSC_VER
    #include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#endif