#include "Source/NeoTypes.h"

sint32 main(sint32 argc, char* *argv)
{
    string str;

    str = strNew();
    strRead(str);
    printf("%s\n", str->String);

    return 0;
}