#include "NeoTypes.h"

int main()
{
    list List;

    for (uint64 i = 0; i < 10; i++)
    {
        List = listNew();
        for (uint64 i = 0; i < 100000000; i++)
        {
            listAppend(List, (void*)i);
        }
        listPurge(List);
        printf("Round %d done.\n", i + 1);
    }

    /*for (uint16 i = 0; i < 3; i++)
    {
        for (uint64 i = 0; i < 10; i++)
        {
            listAppend(List, (void*)i);
        }

        printf("--------\n");
        printf("%d\n", List->Length);
        printf("--------\n");

        listCache(List, 0);
        printf("Cache %d\n", List->List->Length);

        for (uint64 i = 0; i < List->Length; i++)
        {
            printf("%d\n", listGet(List, i)->Value);
        }
    }*/

    return 0;
}