#include "NeoTypes/NeoTypes.h"

#undef main

sint32 main(sint32 argc, char* *argv)
{
    string str;

    str = strNew();
    strInit(str, "Hello World!");
    printf("%s\n", str->String);

    return 0;
}
