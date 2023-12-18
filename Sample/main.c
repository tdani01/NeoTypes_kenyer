#include "NeoTypes/NeoTypes.h"

#undef main

sint32 main(sint32 argc, char* *argv)
{
    string str;
    char* result;

    str = strNew();
    strInit(str, "Hello World!");

    strPurgeKeepString(str, &result);
    printf("%s\n", result);


    return 0;
}
