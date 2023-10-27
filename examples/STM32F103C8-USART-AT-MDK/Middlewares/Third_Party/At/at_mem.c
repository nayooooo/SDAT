#include "at_mem.h"
#include <stdlib.h>
#include <string.h>

void *at_malloc(size_t _Size)
{
    return malloc(_Size);
}

void at_free(void* _Memory)
{
    free(_Memory);
}

void *at_memset(void *_Dst, int _Val, size_t _Size)
{
    return memset(_Dst, _Val, _Size);
}

int at_memcmp(const void *_Buf1, const void *_Buf2, size_t _Size)
{
    return memcmp(_Buf1, _Buf2, _Size);
}

void *at_memcpy(void * _Dst, const void * _Src, size_t _Size)
{
    return memcpy(_Dst, _Src, _Size);
}
