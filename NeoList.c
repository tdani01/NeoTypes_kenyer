#include "NeoTypes.h"

list listNew() //APPROVED
{
    list result;

    result = malloc(sizeof(list));
    result->Cache = NULL;
    result->Length = 0;
    result->CacheCoverage = 0;

    return result;
}

uint16 listAppend(list List, void* Value) //APPROVED
{
    listNode node;

    if (List->Length == 0)
    {
        List->Cache = malloc(sizeof(listNode));

        List->Cache[0] = malloc(sizeof(listNode));
        List->Cache[0]->Value = Value;
        List->Cache[0]->Next = NULL;
    }
    else
    {
        listGet(List, List->Length - 1)->Next = malloc(sizeof(listNode));
        listGet(List, List->Length - 1)->Next->Value = Value;
        listGet(List, List->Length - 1)->Next->Next = NULL;
    }

    List->Length++;
    node = List->Cache[0];
    free(List->Cache);
    List->Cache = malloc(sizeof(listNode));
    List->Cache[0] = node;
    List->CacheCoverage = 0;

    return 0;
}

listNode listGet(list List, uint64 Index) //APPROVED
{
    listNode result;

    uint64 CacheSection;

    if (List->CacheCoverage == 0)
    {
        result = List->Cache[0];
        for (int i = 0; i < Index; i++)
        {
            result = result->Next;
        }
    }
    else
    {
        CacheSection = Index / List->CacheCoverage;

        result = List->Cache[CacheSection];
        for (int i = 0; i < Index - CacheSection * List->CacheCoverage; i++)
        {
            result = result->Next;
        }
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
    for (uint64 i = 0; i < List->Length; i += CacheCoverage)
    {
        CacheSize++;
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