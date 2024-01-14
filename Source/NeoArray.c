#include "NeoTypes.h"

array arrNew(uint64 Length)
{
    array result;

    if ((result = malloc(ARRAY_SIZE)) == NULL)
    {
        printf("arrNew(): Memory allocation failed\nParams: Length: %lld\n", Length);
        exit(1);
    }

    if ((result->Length = Length) == 0)
    {
        result->Values = NULL;
    }
    else
    {
        if ((result->Values = calloc(Length, sizeof(NeoTypes))) == NULL)
        {
            printf("arrNew(): Memory allocation failed\nParams: Length: %lld\n", Length);
            exit(1);
        }
    }

    return result;
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

    for (uint64 i = Array->Length - 1; Index < i; i--)
    {
        Array->Values[i] = Array->Values[i - 1];
    }
    Array->Values[Index].uInt = 0;

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
        printf("arrRemove(): Array must not be empty\nParams: Array: %p, Index: %lld\n", Array, Index);
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

uint8 arrPurge(array Array)
{
    if (Array == NULL)
    {
        return 0;
    }

    free((Array)->Values);
    free(Array);

    return 0;
}