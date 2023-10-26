#include "at_stream_device.h"

#include <stdio.h>

static size_t _print(Stream* this, const char* message)
{
    return printf("%s", message);
}

At_Err_t Stream_Init(Stream* this)
{
    if (this == nullptr) return AT_ERROR;

    this->print = _print;

    return AT_EOK;
}
