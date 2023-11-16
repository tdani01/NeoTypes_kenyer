#include <stdlib.h>
#include <stdarg.h>

#define true 1
#define false 0
typedef char boolean;
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned int uint32;
typedef signed int sint32;
typedef unsigned long uint64;
typedef signed long sint64;

typedef struct
{
    sint64* Values;
    uint64 Length;
} array;

array* arrNew()
{
    array* Array;

    Array = malloc(sizeof(array));
    Array->Values = NULL;
    Array->Length = 0;

    return Array;
}

uint16 arrInit(array* Array, uint64 Length, sint64 Values, ...)
{
    free(Array->Values);

    va_list ValuesArgs;

    Array->Values = malloc(sizeof(sint64) * Length);
    Array->Length = Length;

    va_start(ValuesArgs, Values);
    Array->Values[0] = Values;
    for (uint64 i = 1; i < Length; i++)
    {
        Array->Values[i] = va_arg(ValuesArgs, sint64);
    }
    va_end(ValuesArgs);

    return 0;
}

uint16 arrAppend(array* Array, sint64 Value)
{
    Array->Values = realloc(Array->Values, sizeof(sint64) * (Array->Length + 1));
    Array->Values[Array->Length] = Value;
    Array->Length++;

    return 0;
}

uint16 arrInsert(array* Array, uint64 Index, sint64 Value)
{
    Array->Values = realloc(Array->Values, sizeof(sint64) * (Array->Length + 1));
    Array->Length++;

    for (uint64 i = Array->Length - 1; i > Index; i--)
    {
        Array->Values[i] = Array->Values[i - 1];
    }
    Array->Values[Index] = Value;

    return 0;
}

uint16 arrRemove(array* Array, uint64 Index)
{
    for (uint64 i = Index + 1; i < Array->Length; i++)
    {
        Array->Values[i - 1] = Array->Values[i];
    }

    Array->Values = realloc(Array->Values, sizeof(sint64) * (Array->Length - 1));
    Array->Length--;

    return 0;
}
