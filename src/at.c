#include "at.h"

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

At_Err_t _cutString(At* this, At_Param_t param, const char* atLable)
{
	return AT_EOK;
}

At_State_t _checkString(At* this, At_Param_t param, const char* atLable)
{
	uint32_t i = 0;
	At_State_t target = nullptr;

	this->cutString(this, param, atLable);

	while (this->_atTable[i].atLable != AT_LABLE_TAIL)
	{
        if (!memcmp(this->_atTable[i].atLable, param->cmd, strlen(this->_atTable[i].atLable)))
		{
			target = &this->_atTable[i];
			break;
		}
		i++;
	}

    return target;
}

static size_t _getParamMaxNum(At* this)
{
    if (this == nullptr) return -1;
    return this->_param_max_num;
}

static At_State_t _getStateTable(At* this)
{
    if (this == nullptr) return nullptr;
    return this->_atTable;
}

At_Err_t _setInputDevice(At* this, Stream* input_dev)
{
    if (this == nullptr) return AT_ERROR;
    if (input_dev == nullptr) return AT_ERROR;
    this->_input_dev = input_dev;
    return AT_EOK;
}

At_Err_t _setOutputDevice(At* this, Stream* output_dev)
{
    if (this == nullptr) return AT_ERROR;
    if (output_dev == nullptr) return AT_ERROR;
    this->_output_dev = output_dev;
    return AT_EOK;
}

// dangerous
const char* _errorToString(At_Err_t error)
{
    static char error_str[50];

    memset(error_str, 0, sizeof(error_str));
	switch (error)
	{
	case AT_ERROR:
        memcpy(error_str, "AT normal error", 16); break;
	case AT_ERROR_INPUT:
        memcpy(error_str, "AT input device error", 22); break;
	case AT_ERROR_OUTPUT:
        memcpy(error_str, "AT output device error", 23); break;
	case AT_ERROR_NOT_FIND:
        memcpy(error_str, "AT not find this string command", 32); break;
	case AT_ERROR_NO_ACT:
        memcpy(error_str, "AT this string command not have act", 36); break;
	case AT_ERROR_CANNOT_CUT:
        memcpy(error_str, "AT this string can't be cut", 28); break;
    default:
        memcpy(error_str, "AT no error", 12); break;
	}
    return error_str;
}

// safer
const char* _errorToString_s(At_Err_t error)
{
    static char error_str[12];
    memset(error_str, 0, sizeof(error_str));
    memcpy(error_str, "building...", 11);
    return error_str;
}

At_Err_t _handle(At* this, const char* atLable)
{
    if (this == nullptr) return AT_ERROR;

	struct At_Param param;
    At_State_t target = this->checkString(this, &param, atLable);

	if (target == nullptr)
		return AT_ERROR_NOT_FIND;
	if (target->act == nullptr)
		return AT_ERROR_NO_ACT;

    return target->act(&param);
}

static At_Err_t _At_Init(
    At* this,
    const At_State_t atTable, Stream* input_dev, Stream* output_dev,
    size_t param_max_num, char terminator, size_t readString_len
)
{
    if (this == nullptr) return AT_ERROR;
    if (atTable == nullptr) return AT_ERROR;
    if (input_dev == nullptr) return AT_ERROR;
    if (output_dev == nullptr) return AT_ERROR;
    if (readString_len <= 3) return AT_ERROR;  // AT+

    this->_atTable = atTable;
    this->_input_dev = input_dev;
    this->_output_dev = output_dev;
    this->_param_max_num = param_max_num;
    this->_terminator = terminator;
    this->_readString_len = readString_len;

    this->_readString = (char*)malloc(readString_len * sizeof(char));
    if (this->_readString == nullptr) return AT_ERROR;
    memset(this->_readString, 0, this->_readString_len);

    this->cutString = _cutString;
    this->checkString = _checkString;

    this->getParamMaxNum = _getParamMaxNum;
    this->getStateTable = _getStateTable;

    this->setInputDevice = _setInputDevice;
    this->setOutputDevice = _setOutputDevice;

    this->errorToString = _errorToString;
    this->handle = _handle;

    return AT_EOK;
}

At_Err_t At_Init(
    At* this,
    const At_State_t atTable, Stream* input_dev, Stream* output_dev,
    size_t argc, ...
)
{
    if (argc == 0) {
        return _At_Init(this, atTable, input_dev, output_dev, AT_PARAM_MAX_NUM, AT_TERMINATOR_DEFAULT, AT_READSTRING_LEN_DEFAULT);
    } else if (argc > 3) return AT_ERROR;
    va_list args;
    va_start(args, argc);
    size_t temp = argc;
    size_t param_max_num; char terminator; size_t readString_len;
    param_max_num = va_arg(args, size_t); if (--temp) {
        return _At_Init(this, atTable, input_dev, output_dev, param_max_num, AT_TERMINATOR_DEFAULT, AT_READSTRING_LEN_DEFAULT);
    }
    terminator = va_arg(args, char); if (--temp) {  // dangerous at "va_arg(args, char)", the "char"
        return _At_Init(this, atTable, input_dev, output_dev, param_max_num, terminator, AT_READSTRING_LEN_DEFAULT);
    }
    readString_len = va_arg(args, size_t); if (--temp) {
        return _At_Init(this, atTable, input_dev, output_dev, param_max_num, terminator, readString_len);
    }

    return AT_ERROR;
}

At_Err_t At_Init_s(
    At* this,
    const At_State_t atTable, Stream* input_dev, Stream* output_dev,
    size_t param_max_num, char terminator, size_t readString_len
)
{
    return _At_Init(this, atTable, input_dev, output_dev, param_max_num, terminator, readString_len);
}
