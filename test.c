#include <stdio.h>
#include "NeoTypes.h"

int main()
{
    array arr = arrNew();

    arrInit(arr, 4, 1, 2, 3, 4);

    arrInsert(arr, 0, 69);
    arrInsert(arr, arr->Length, 96);
    arrInsert(arr, arr->Length, 44);
    arrRemove(arr, arr->Length - 2);

    for (uint64 i = 0; i < arr->Length; i++)
    {
        printf("%d ", arr->Values[i]);
    }
    printf("\n%d\n", arr->Length);

    return 0;
}