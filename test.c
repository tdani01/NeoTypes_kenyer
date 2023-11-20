#include <stdio.h>
#include "NeoTypes.h"

int main()
{
    string str = strNew();
    strInit(str, "Hello");
    strConcat(str, 3, str->String, " ", "World!");

    printf("%s %d %d\n", str->String, str->Lenght, strLength(str->String));

    return 0;
}