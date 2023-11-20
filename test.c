#include <stdio.h>
#include "NeoTypes.h"

int main()
{
    array arr = arrNew(0);

    arrInit(arr, 4, 1, 2, 3, 4);

    for (uint64 i = 0; i < arr->Length; i++)
    {
        printf("%d\n", arr->Values[i]);
    }

    return 0;
}