#include "NeoTypes.h"

list listNew() //APPROVED
{
    list result;

    result = malloc(sizeof(list));
    result->Cache = NULL;
    result->Length = 0;
    result->CacheCoverage = result->Length;

    return result;
}

uint16 listAppend(list List, void* Value) //APPROVED
{
    if (List->Cache == NULL)
    {
        List->Cache = malloc(sizeof(listNode));

        List->Cache[0] = malloc(sizeof(listNode));
        ((listNode)List->Cache[0])->Value = Value;
        ((listNode)List->Cache[0])->Next = NULL;

        List->Length++;
        List->CacheCoverage = List->Length;

        return 0;
    }

    listGet(List, List->Length - 1)->Next = malloc(sizeof(listNode));
    listGet(List, List->Length - 1)->Next->Value = Value;
    listGet(List, List->Length - 1)->Next->Next = NULL;

    List->Length++;
    List->CacheCoverage = List->Length;

    return 0;
}

listNode listGet(list List, uint64 Index) //APPROVED
{
    listNode result;

    uint64 CacheSection;

    CacheSection = Index / List->CacheCoverage;

    result = List->Cache[CacheSection];
    for (int i = 0; i < Index - CacheSection * List->CacheCoverage; i++)
    {
        result = result->Next;
    }

    return result;
}

uint16 listCache(list List, uint64 CacheCoverage) //APPROVED
{
    listNode node;
    uint64 CacheSize;

    List->CacheCoverage = CacheCoverage;

    //Calculate the size of the cache
    CacheSize = 0;
    for (uint64 i = 0; i < List->Length; i++)
    {
        if (i % List->CacheCoverage == 0)
        {
            CacheSize++;
        }
    }

    //Initialize the cache
    node = List->Cache[0];
    free(List->Cache);
    List->Cache = malloc(sizeof(listNode) * CacheSize);

    //Fill the cache
    for (uint64 i = 0; i < List->Length; i++)
    {
        if (i % List->CacheCoverage == 0)
        {
            List->Cache[i / List->CacheCoverage] = node;
        }
        
        node = node->Next;
    }

    return 0;
}