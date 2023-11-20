#include <stdio.h>
#include "NeoTypes.h"

int main()
{
    string str = strNew();
    strInit(str, "Hello World split this string !");

    array arr = arrNew();

    strSplit(arr, str, ' ');
    for (uint64 i = 0; i < arr->Length; i++)
    {
        printf("%s\n", ((string)arr->Values[i])->String);
    }

    return 0;
}