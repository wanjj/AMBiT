#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <new>

#ifdef WIN32
    #pragma warning ( disable : 4786 )
    #pragma warning ( disable : 4290 )
    #pragma warning ( disable : 4503 )
    #pragma warning ( disable : 4267 )  // conversion from * to *, possible loss of data

    #define WIN32_LEAN_AND_MEAN     // Exclude rarely-used stuff from Windows headers
    #define mmin std::min
    #define mmax std::max

    #define PAUSE getchar();

#else
    #ifndef UNIX
        #define UNIX
    #endif

    #ifdef GCC
        #define mmin(i, j) (i <? j)
        #define mmax(i, j) (i >? j)
    #else
        #define mmin(i, j) (((i) < (j))?(i):(j))
        #define mmax(i, j) (((i) > (j))?(i):(j))
    #endif

    #define PAUSE
#endif

#endif
