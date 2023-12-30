#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

//_____________________________________________NeoTypes.h____________________________________________//

#define true 1
#define false 0
typedef unsigned char logic;
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned int uint32;
typedef signed int sint32;
typedef unsigned long long uint64;
typedef signed long long sint64;

typedef struct arrayStruct* array;
typedef struct stringStruct* string;
typedef struct listStruct* list;
typedef struct listCacheStruct* listCache_t;
typedef struct listNodeStruct* listNode;

typedef union
{
    logic Logic;

    uint64 uInt;
    sint64 sInt;
    double Double;

    array Array;
    string String;
    list List;

    void* Pointer;
    
} NeoTypes;

//_____________________________________________NeoArray.c____________________________________________//

struct arrayStruct
{
    NeoTypes* Values;
    uint64 Length;
};

array arrNew(uint64 Length);

NeoTypes* arrElement(array Array, uint64 Index);
NeoTypes* arrInsert(array Array, uint64 Index);
uint8 arrRemove(array Array, uint64 Index);

uint8 arrPurge(array* Array);

//____________________________________________NeoString.c____________________________________________//

struct stringStruct
{
    char* String;
    uint64 Length;
};

uint64 strLength(char* Characters);

string strNew();

uint8 strInit(string String, char* Characters);
uint8 strAppend(string String, char Character);

uint8 strConcat(string String, uint64 Count, char* Characters, ...);
uint8 strRead(string String);
uint8 strSplit(array Array, char* Characters, char Character);

logic strCompare(char* Characters1, char* Characters2);

uint8 strPurge(string String);

//_____________________________________________NeoList.c_____________________________________________//

struct listStruct
{
    listCache_t Cache;
    uint64 Length;
};
struct listCacheStruct
{
    listNode* Nodes;
    uint64 Size;
    uint64 Coverage;
};
struct listNodeStruct
{
    listNode Next;
    void* Value;
};

list listNew();

uint8 listInsert(list List, uint64 Index, void* Value);
uint8 listRemove(list List, uint64 Index);
listNode listGet(list List, uint64 Index);

uint8 listCache(list List, uint64 CacheCoverage);

uint8 listPurge(list List);

//____________________________________________NeoConvert.c___________________________________________//

uint64 STRtoUINT(char* Characters, logic* Success);
uint8 UINTtoSTR(uint64 Number, string String);

sint64 STRtoSINT(char* Characters, logic* Success);
uint8 SINTtoSTR(sint64 Number, string String);

double STRtoDOUBLE(char* Characters, logic* Success);
uint8 DOUBLEtoSTR(double Number, string String);

//_____________________________________________NeoFile.c_____________________________________________//

uint8 fileRead(char* FilePath, array Lines);
uint8 fileWrite(array Lines, char* FilePath);

//____________________________________________NeoMemory.c____________________________________________//

uint8 memAlloc(void** PTR, uint64 Size);
uint8 memCalloc(void** PTR, uint64 Size);
uint8 memRealloc(void** PTR, uint64 Size);
uint8 memFree(void** PTR);

void* memCopy(void* Source, uint64 Size);
uint8 memCopyTo(void* Source, void* Destination, uint64 Size);

void* memLoad(char* FilePath, uint64 Size);
uint8 memLoadTo(char* FilePath, void* Destination, uint64 Size);
uint8 memSave(void* Area, uint64 Size, char* FilePath);