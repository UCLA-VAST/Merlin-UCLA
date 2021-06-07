#ifndef ROSE_TIMING_H
#define ROSE_TIMING_H
/*
07/17/2017 This is moved from src/3rdPartyLibraries/POET 
to remove dependece on POET
*/

#ifdef _MSC_VER
#include <winsock.h> /* struct timeval */
// replacement gettimeofday function for Windows
// If we only put the function signature here, we encounter the
// following error while compiling fixupInClassDataInitialization.C:
// error C2129: static function declared but not defined
static int
gettimeofday(struct timeval *tp, void *dummy)
{
    FILETIME        ft;
    LARGE_INTEGER   li;
    __int64         t;

   SYSTEMTIME      st;
   FILETIME        ft2;
   LARGE_INTEGER   li2;
    __int64        t2;

    st.wYear = 1970;
    st.wHour = 0;
    st.wMinute = 0;
    st.wSecond = 0;
    st.wMilliseconds = 1;

    SystemTimeToFileTime(&st, &ft2);
    li2.LowPart = ft2.dwLowDateTime;
    li2.HighPart = ft2.dwHighDateTime;
    t2 = li2.QuadPart;

    GetSystemTimeAsFileTime(&ft);
    li.LowPart  = ft.dwLowDateTime;
    li.HighPart = ft.dwHighDateTime;
    t  = li.QuadPart;      
    t -= t2; // From 1970
    t /= 10; // In microseconds
    tp->tv_sec  = (long)(t / 1000000);
    tp->tv_usec = (long)(t % 1000000);
    return 0;
}
#else
#include <sys/time.h>
#endif

#endif
