#include <stdio.h>
#include "NeoTypes.h"

int main()
{
    array arr = arrNew(3);

    for (uint64 i = 0; i < arr->Length; i++)
    {
        printf("%d\n", arr->Values[i]);
    }

    return 0;
}