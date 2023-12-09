#include "NeoTypes/NeoTypes.h"

#undef main

uint8 main(uint8 argc, char* *argv)
{
    string str;

    str = strNew();
    strInit(str, "Hello World!");
    printf("%s\n", str->String);

    return 0;
}
