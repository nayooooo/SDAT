#include "at.h"

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

static At_Err_t _At_Init(
    At* at,
    const At_State_t atTable, Stream* input_dev, Stream* output_dev,
    size_t param_max_num, char terminator, size_t readString_len
)
{
    if (at == nullptr) return AT_ERROR;
    if (atTable == nullptr) return AT_ERROR;
    if (input_dev == nullptr) return AT_ERROR;
    if (output_dev == nullptr) return AT_ERROR;
    if (readString_len <= 3) return AT_ERROR;  // AT+

    at->_atTable = atTable;
    at->_input_dev = input_dev;
    at->_output_dev = output_dev;
    at->_param_max_num = param_max_num;
    at->_terminator = terminator;
    at->_readString_len = readString_len;

    at->_readString = (char*)malloc(readString_len * sizeof(char));
    if (at->_readString == nullptr) return AT_ERROR;
    memset(at->_readString, 0, at->_readString_len);

    return AT_EOK;
}

At_Err_t At_Init(
    At* at,
    const At_State_t atTable, Stream* input_dev, Stream* output_dev,
    size_t argc, ...
)
{
    if (argc == 0) {
        return _At_Init(at, atTable, input_dev, output_dev, AT_PARAM_MAX_NUM, AT_TERMINATOR_DEFAULT, AT_READSTRING_LEN_DEFAULT);
    } else if (argc > 3) return AT_ERROR;
    va_list args;
    va_start(args, argc);
    size_t temp = argc;
    size_t param_max_num; char terminator; size_t readString_len;
    param_max_num = va_arg(args, size_t); if (--temp) {
        return _At_Init(at, atTable, input_dev, output_dev, param_max_num, AT_TERMINATOR_DEFAULT, AT_READSTRING_LEN_DEFAULT);
    }
    terminator = va_arg(args, char); if (--temp) {  // dangerous at "va_arg(args, char)", the "char"
        return _At_Init(at, atTable, input_dev, output_dev, param_max_num, terminator, AT_READSTRING_LEN_DEFAULT);
    }
    readString_len = va_arg(args, size_t); if (--temp) {
        return _At_Init(at, atTable, input_dev, output_dev, param_max_num, terminator, readString_len);
    }

    return AT_ERROR;
}

At_Err_t At_Init_s(
    At* at,
    const At_State_t atTable, Stream* input_dev, Stream* output_dev,
    size_t param_max_num, char terminator, size_t readString_len
)
{
    return _At_Init(at, atTable, input_dev, output_dev, param_max_num, terminator, readString_len);
}
