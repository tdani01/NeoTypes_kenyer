#include "NeoTypes.h"

int main()
{
    list lista = listNew();

    for (uint64 i = 0; i < 1000000; i++)
    {
        listAppend(lista,(void*)i);
    }
    printf("appended\n");

    listCache(lista, lista->Length);
    printf("cached %d\n", lista->List->Length);

    for (uint64 i = 0; i < lista->Length; i++)
    {
        printf("%d\n", listGet(lista, i)->Value);
    }
    printf("got\n");

    return 0;
}