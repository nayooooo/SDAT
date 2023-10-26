#ifndef __AT_STREAM_DEVICE_H__
#define __AT_STREAM_DEVICE_H__

#include "at_type.h"

struct At_Stream_Device{
    size_t (*print)(struct At_Stream_Device* this, const char* message);
};
typedef struct At_Stream_Device Stream;

At_Err_t Stream_Init(Stream* this);

#endif  // !__AT_STREAM_DEVICE_H__
