#include "at.h"

#include <stdio.h>

struct At_State _at_table[] = {
    { AT_LABLE_TAIL, AT_TYPE_NULL, nullptr },
};

int main()
{
    At at;
    Stream dev;
    Stream_Init(&dev);
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

    return 0;
}
