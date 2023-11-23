#include "NeoTypes.h"

int main()
{
    list List = listNew();

    for (uint16 i = 0; i < 3; i++)
    {
        for (uint64 i = 0; i < 10; i++)
        {
            listAppend(List, (void*)i);
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
    }

    return 0;
}