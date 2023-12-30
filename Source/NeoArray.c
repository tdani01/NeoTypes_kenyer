#include "NeoTypes.h"
#include <stdio.h>

#define ARRAY_SIZE (sizeof(void*) + sizeof(uint64))

array arrNew(uint64 Length)
{
    array Array;

    Array = (array)malloc(ARRAY_SIZE);
    if (Array == NULL)
    {
        printf("arrNew(): Memory allocation failed\nArguments: Length: %lld\n", Length);
        exit(1);
    }

    if (Length == 0)
    {
        Array->Values = NULL;
        Array->Length = 0;
    }
    else
    {
        Array->Values = (void**)calloc(Length, sizeof(void*));
        if (Array->Values == NULL)
        {
            printf("arrNew(): Memory allocation failed\nArguments: Length: %lld\n", Length);
            exit(1);
        }
        Array->Length = Length;
    }

    return Array;
}

uint8 arrInit(array Array, uint64 Length, void* Values, ...)
{
    va_list ValuesArgs;

    if (Length == 0)
    {
        printf("arrInit(): Length must be greater than 0\nArguments: Array: %p, Length: %lld, Values: %p\n", Array, Length, Values);
        exit(1);
    }

    free(Array->Values);
    Array->Values = (void**)malloc(sizeof(void*) * Length);
    if (Array->Values == NULL)
    {
        printf("arrInit(): Memory allocation failed\nArguments: Array: %p, Length: %lld, Values: %p\n", Array, Length, Values);
        exit(1);
    }
    Array->Length = Length;

    va_start(ValuesArgs, Values);
    Array->Values[0] = Values;
    for (uint64 i = 1; i < Length; i++)
    {
        Array->Values[i] = va_arg(ValuesArgs, void*);
    }
    va_end(ValuesArgs);

    return 0;
}

uint8 arrInsert(array Array, uint64 Index, void* Value)
{
    if (Array->Length < Index)
    {
        printf("arrInsert(): Index out of range\nArguments: Array: %p, Index: %lld, Value: %p\n", Array, Index, Value);
        exit(1);
    }

    Array->Length++;
    Array->Values = (void**)realloc(Array->Values, sizeof(void*) * Array->Length);
    if (Array->Values == NULL)
    {
        printf("arrInsert(): Memory allocation failed\nArguments: Array: %p, Index: %lld, Value: %p\n", Array, Index, Value);
        exit(1);
    }

    for (uint64 i = Array->Length - 1; i > Index; i--)
    {
        Array->Values[i] = Array->Values[i - 1];
    }
    Array->Values[Index] = Value;

    return 0;
}

uint8 arrRemove(array Array, uint64 Index)
{
    if (Array->Length < Index)
    {
        printf("arrRemove(): Index out of range\nArguments: Array: %p, Index: %lld\n", Array, Index);
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
        Array->Values = (void**)realloc(Array->Values, sizeof(void*) * Array->Length);
        if (Array->Values == NULL)
        {
            printf("arrRemove(): Memory allocation failed\nArguments: Array: %p, Index: %lld\n", Array, Index);
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