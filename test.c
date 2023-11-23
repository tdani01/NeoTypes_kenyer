#include "NeoTypes.h"

int main()
{
    string str = strNew();
    strInit(str, "hello world szia uram hogy vagy ma !");
    array arr = arrNew(0);
    strSplit(arr, str, ' ');
    for (uint64 i = 0; i < arr->Length; i++)
    {
        printf("%s\n", ((string)arr->Values[i])->String);
    }


    /*for (uint16 i = 0; i < 3; i++)
    {
        for (uint64 i = 0; i < 10; i++)
        {
            listInsert(List, List->Length, (void*)i);
        }

        printf("--------\n");
        printf("%d\n", List->Length);
        printf("--------\n");

        listCache(List, 3);
        printf("Cache %d\n", List->Cache->Size);

        for (uint64 i = 0; i < List->Length; i++)
        {
            printf("%d\n", listGet(List, i)->Value);
        }
    }*/

    return 0;
}