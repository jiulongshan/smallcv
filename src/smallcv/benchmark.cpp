/*
 * @Author: your name
 * @Date: 2021-12-24 15:47:34
 * @LastEditTime: 2021-12-29 15:03:28
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /smallcv1/src/smallcv/benchmark.cpp
 */
#include "smallcv/benchmark.hpp"
#include <stdio.h>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#else // _WIN32
#include <sys/time.h>
#include <unistd.h>
#endif // _WIN32

#include <stddef.h>


double scv::get_current_time()
{
#ifdef _WIN32
    LARGE_INTEGER freq;
    LARGE_INTEGER pc;
    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&pc);

    return pc.QuadPart * 1000.0 / freq.QuadPart;
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);

    return tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0;
#endif // _WIN32
}

void scv::sleep(int milli_secs) {
#ifdef _MSC_VER
    Sleep(milli_secs);
#elif defined(__linux__)
    usleep(milli_secs * 1000); // 1 ms = 1000 us
#endif
}