#include "at.h"

#include <stdlib.h>
#include <string.h>

At_Err_t At_Init(
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
