#include "NeoTypes.h"

int main()
{
    string str = strNew();
    strInit(str, "Hello World!");

    printf("%s\n", str->String);

    return 0;
}