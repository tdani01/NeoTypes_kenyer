#include "NeoTypes.h"

int main()
{
    list List = listNew();

    listInsert(List, List->Length, (void*)1);
    listInsert(List, List->Length, (void*)2);
    listInsert(List, List->Length, (void*)3);

    for (uint64 i = 0; i < List->Length; i++)
    {
        printf("%d\n", listGet(List, i)->Value);
    }

    printf("------\n");
    listRemove(List, 2);

    for (uint64 i = 0; i < List->Length; i++)
    {
        printf("%d\n", listGet(List, i)->Value);
    }

    printf("------\n");

    listInsert(List, 2, (void*)4);
    listInsert(List, List->Length, (void*)5);
    listInsert(List, List->Length, (void*)6);
    for (uint64 i = 0; i < List->Length; i++)
    {
        printf("%d\n", listGet(List, i)->Value);
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