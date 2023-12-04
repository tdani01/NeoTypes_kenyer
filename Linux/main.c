#include "NeoTypes/NeoTypes.h"

#undef main

uint16 main(uint64 argc, char* *argv)
{
    string str;

    str = strNew();
    strInit(str, "Hello World!");
    printf("%s\n", str->String);

    return 0;
}