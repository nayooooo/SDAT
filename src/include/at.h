#ifndef __AT_H__
#define __AT_H__

#include "at_type.h"
#include "at_stream_device.h"

#define AT_TERMINATOR_DEFAULT            ('\n')
#define AT_READSTRING_LEN_DEFAULT        (200)

struct At{
    At_Err_t (*cutString)(At* this, At_Param_t param, const char* atLable);
	At_State_t (*checkString)(At* this, At_Param_t param, const char* atLable);

    size_t (*getParamMaxNum)(At* this);
    At_State_t (*getStateTable)(At* this);

    At_Err_t (*setInputDevice)(At* this, Stream* input_dev);
    At_Err_t (*setOutputDevice)(At* this, Stream* output_dev);

    const char* (*errorToString)(At_Err_t error);

    At_Err_t (*handle)(At* this, const char* atLable);
    At_Err_t (*handleAuto)(At* this);

    size_t (*printf)(At* this, const char* format, ...)  __attribute__ ((format (printf, 2, 3)));
    size_t (*print)(At* this, const char* message);
    size_t (*println)(At* this, const char* message);
    At_Err_t (*printSet)(At* this, const char* name);
    At_Err_t (*sendInfor)(At* this, const char* infor);

    At_State_t _atTable;
    Stream* _input_dev;
    Stream* _output_dev;
    size_t _param_max_num;
    char _terminator;
    char* _readString;
    size_t _readString_len;
};
typedef struct At At;

// dangerous
At_Err_t At_Init(
    At* this,
    const At_State_t atTable, Stream* input_dev, Stream* output_dev,
    size_t argc, ...
);

// safer
At_Err_t At_Init_s(
    At* this,
    const At_State_t atTable, Stream* input_dev, Stream* output_dev,
    size_t param_max_num, char terminator, size_t readString_len
);

#endif  // !__AT_H__
