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

array* arrNew();
uint16 arrInit(array* Array, uint64 Length, sint64 Values, ...);
uint16 arrAppend(array* Array, sint64 Value);
uint16 arrInsert(array* Array, uint64 Index, sint64 Value);
uint16 arrRemove(array* Array, uint64 Index);
sint64 asLong(double number);
double asDouble(sint64 number);