#ifndef __AT_STREAM_DEVICE_H__
#define __AT_STREAM_DEVICE_H__

#include "at.h"

struct At_Stream_Device{
    size_t (*print)(struct At_Stream_Device* this, const char* message);
};
typedef struct At_Stream_Device Stream;

#endif  // !__AT_STREAM_DEVICE_H__
