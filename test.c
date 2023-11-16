#include <stdio.h>
#include "NeoTypes.h"

int main()
{
    array* Array = arrNew();

    arrInit(Array, 4, 1, 2, 3, 4);
    arrAppend(Array, 7);
    arrInsert(Array, 0, 69);
    arrInsert(Array, Array->Length, 49);
    arrRemove(Array, 6);

    for (uint64 i = 0; i < Array->Length; i++)
    {
        printf("%d\n", Array->Values[i]);
    }

    return 0;
}