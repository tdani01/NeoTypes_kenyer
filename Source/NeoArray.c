#include "NeoTypes.h"

#define ARRAY_SIZE (sizeof(NeoTypes) + sizeof(uint64))

array arrNew(uint64 Length)
{
    array Array;

    Array = (array)malloc(ARRAY_SIZE);
    if (Array == NULL)
    {
        printf("arrNew(): Memory allocation failed\nParams: Length: %lld\n", Length);
        exit(1);
    }

    if (Length == 0)
    {
        Array->Values = NULL;
        Array->Length = 0;
    }
    else
    {
        Array->Values = (NeoTypes*)calloc(Length, sizeof(NeoTypes));
        if (Array->Values == NULL)
        {
            printf("arrNew(): Memory allocation failed\nParams: Length: %lld\n", Length);
            exit(1);
        }
        Array->Length = Length;
    }

    return Array;
}

NeoTypes* arrElement(array Array, uint64 Index)
{
    if (Array == NULL)
    {
        printf("arrElement(): Array must not be NULL\nParams: Array: %p, Index: %lld\n", Array, Index);
        exit(1);
    }
    if (Array->Length <= Index)
    {
        printf("arrElement(): Index out of range\nParams: Array: %p, Index: %lld\n", Array, Index);
        exit(1);
    }

    return &Array->Values[Index];
}

NeoTypes* arrInsert(array Array, uint64 Index)
{
    if (Array == NULL)
    {
        printf("arrInsert(): Array must not be NULL\nParams: Array: %p, Index: %lld\n", Array, Index);
        exit(1);
    }
    if (Array->Length < Index)
    {
        printf("arrInsert(): Index out of range\nParams: Array: %p, Index: %lld\n", Array, Index);
        exit(1);
    }

    Array->Length++;
    Array->Values = (NeoTypes*)realloc(Array->Values, sizeof(NeoTypes) * Array->Length);
    if (Array->Values == NULL)
    {
        printf("arrInsert(): Memory allocation failed\nParams: Array: %p, Index: %lld\n", Array, Index);
        exit(1);
    }

    for (uint64 i = Array->Length - 1; i > Index; i--)
    {
        Array->Values[i] = Array->Values[i - 1];
    }
    Array->Values[Index].Pointer = NULL;

    return &Array->Values[Index];
}

uint8 arrRemove(array Array, uint64 Index)
{
    if (Array == NULL)
    {
        printf("arrRemove(): Array must not be NULL\nParams: Array: %p, Index: %lld\n", Array, Index);
        exit(1);
    }
    if (Array->Length <= Index)
    {
        printf("arrRemove(): Index out of range\nParams: Array: %p, Index: %lld\n", Array, Index);
        exit(1);
    }
    if (Array->Length == 0)
    {
        printf("arrRemove(): Empty array\nParams: Array: %p, Index: %lld\n", Array, Index);
        exit(1);
    }

    for (uint64 i = Index; i < Array->Length - 1; i++)
    {
        Array->Values[i] = Array->Values[i + 1];
    }

    Array->Length--;
    if (Array->Length == 0)
    {
        free(Array->Values);
        Array->Values = NULL;
    }
    else
    {
        Array->Values = (NeoTypes*)realloc(Array->Values, sizeof(NeoTypes) * Array->Length);
        if (Array->Values == NULL)
        {
            printf("arrRemove(): Memory allocation failed\nParams: Array: %p, Index: %lld\n", Array, Index);
            exit(1);
        }
    }

    return 0;
}

uint8 arrPurge(array* Array)
{
    if (*Array == NULL)
    {
        return 0;
    }

    free((*Array)->Values);
    free(*Array);
    *Array = NULL;

    return 0;
}