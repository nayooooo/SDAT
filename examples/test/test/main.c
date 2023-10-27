#include "at.h"

#include <stdio.h>

#pragma comment(lib, "legacy_stdio_definitions.lib")

static size_t _print(Stream* this, const char* message)
{
    return printf("%s", message);
}

static At_Err_t main_at_user_AT(At_Param_t param);
static At_Err_t main_at_user_AT_List(At_Param_t param);
struct At_State _at_table[] = {
    { "AT", AT_TYPE_CMD, main_at_user_AT },
    { "AT+LS", AT_TYPE_CMD, main_at_user_AT_List },
    { AT_LABLE_TAIL, AT_TYPE_NULL, nullptr },
};
static At at;

static At_Err_t main_at_user_AT(At_Param_t param)
{
    at.sendInfor(&at, "OK");
    return AT_EOK;
}

static At_Err_t main_at_user_AT_List(At_Param_t param)
{
    at.printSet(&at, "at");
    return AT_EOK;
}

int main()
{
    Stream dev;
    Stream_Init_s(&dev, _print, _print, _print);
    dev.print(&dev, "input and output device is initialized!\r\n");
    At_Init(&at, _at_table, &dev, &dev, 0);
    at.print(&at, "test at.print\r\n");
    at.printf(&at, "_atTable:        %p\r\n", at._atTable);
    at.printf(&at, "_input_dev:      %p\r\n", at._input_dev);
    at.printf(&at, "_output_dev:     %p\r\n", at._output_dev);
    at.printf(&at, "_param_max_num:  %d\r\n", (int)at._param_max_num);
    at.printf(&at, "_terminator:     %c\r\n", at._terminator);
    at.printf(&at, "_readString:     %s\r\n", at._readString);
    at.printf(&at, "_readString_len: %d\r\n", (int)at._readString_len);
    at.printSet(&at, "at");
    at.sendInfor(&at, "Hello World!");
    at.handle(&at, "AT");
    at.handle(&at, "AT+LS");

    return 0;
}
