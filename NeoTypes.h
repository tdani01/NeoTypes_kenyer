#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

/*Dynamically sized array with 8 byte (void*) values.
Get or set the value of an element in an array: Array->Values[index].
Get the length of an array: Array->Length.
Note: every array function starts with the "arr" keyword.*/
typedef struct arrayStruct* array;

/*Dynamically sized ASCII string.
Get the string of a string: String->String.
Get the length of a string: String->Length.
Note: '\0' is included in the length of the string, every string function starts with the "str" keyword.*/
typedef struct stringStruct* string;

/*List with 8 byte (void*) values.
Get or set the value of an element in a list: listGet(List, index)->Value.
Get the length of a list: List->Length.
Note: every list function starts with the "list" keyword.*/
typedef struct listStruct* list;
typedef struct listCacheStruct* listCache_t;
typedef struct listNodeStruct* listNode;

//_____________________________________________NeoTypes.h____________________________________________//

#define true 1
#define false 0
/*Also known as bool or boolean.*/
typedef char logic;
typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned short uint16;
typedef signed short sint16;
typedef unsigned int uint32;
typedef signed int sint32;
typedef unsigned long uint64;
typedef signed long sint64;

//_____________________________________________NeoCast.c_____________________________________________// COMPLETED

/*Process a binary value stored in a double as an integer.*/
uint64 asInt(double Value);
/*Process a binary value stored in an integer as a double.*/
double asDouble(uint64 Value);

//_____________________________________________NeoArray.c____________________________________________// COMPLETED

struct arrayStruct
{
    void* *Values;
    uint64 Length;
};

/*Creates a new array with the given length.
Returns the address of the array or NULL if fails.
Warning: calling this function on an initialized array can cause memory leaks, before calling this function second time you must use arrPurge().
Important: you must always initialize an array with this function before use.*/
array arrNew(uint64 Length);
/*Clears the elements of the given array and initializes it with the new ones.
Returns 0 on success and 1 on error.
Warning: if fails the Array->Values will be NULL and the Array->Length will be 0.
Important: if the previous elements of the array were pointers allocated with a malloc(), calloc() or realloc() it's recommended to first call free() on those pointers to avoid memory leaks.
Note: this function can not replace the arrNew() function.*/
uint8 arrInit(array Array, uint64 Length, void* Values, ...);

/*Inserts a new element into an array.
To add a new element to the end of an array you must use Array->Length as index.
Returns 0 on success and 1 on error.
Warning: if fails the Array->Values will be NULL and the Array->Length will be 0.
Important: failures can lead to memory leaks.*/
uint8 arrInsert(array Array, uint64 Index, void* Value);
/*Removes an element from an array at the given index.
Returns 0 on success and 1 on error.
Warning: if fails the Array->Values will be NULL and the Array->Length will be 0.
Important: if the element to be removed is a pointer allocated with a malloc(), calloc() or realloc() it's recommended to call free() on it to avoid memory leaks, failures can lead to memory leaks.*/
uint8 arrRemove(array Array, uint64 Index);

/*Deallocates an array from the memory with all of its elements.
Important: if the elements of the array were pointers allocated with a malloc(), calloc() or realloc() it's recommended to first call free() on those pointers to avoid memory leaks.
Note: it's recommended to set the Array's value to NULL after calling this function, it's safe to pass a NULL value to this function.*/
uint8 arrPurge(array Array);

//____________________________________________NeoString.c____________________________________________// COMPLETED

struct stringStruct
{
    char* String;
    uint64 Length;
};

/*Returns the length of a string (char*) with the '\0' included.*/
uint64 strLength(char* Characters);

/*Creates a new string, the String->String will be "\0" and the String->Length will be 1.
Returns the address of the string or NULL if fails.
Warning: calling this function on an initialized string can cause memory leaks, before calling this function second time you must use strPurge().
Important: you must always initialize a string with this function before use.*/
string strNew();
/*Clears the string of the given string and initializes it with the new one.
Returns 0 on success and 1 on error.
Warning: if fails the String->String will be NULL and the String->Length will be 0.
Note: this function can not replace the strNew() function.*/
uint8 strInit(string String, char* Characters);

/*Appends a new character to the end of the string.
Returns 0 on success and 1 on error.
Warning: if fails the String->String will be NULL and the String->Length will be 0.
Important: failures can lead to memory leaks.*/
uint8 strAppend(string String, char Character);
/*Concatenates two or more strings into one string.
Returns 0 on success and 1 on error.
Important: the number of the strings will be concatenated must be accurate.
Note: deallocating the target string is not needed, if fails every string will remain intact.*/
uint8 strConcat(string String, uint64 Count, char* Characters, ...);


uint8 strRead(string String);
uint8 strSplit(array Array, char* Characters, char Character);
logic strCompare(char* Characters1, char* Characters2);

uint8 strPurge(string String);

//_____________________________________________NeoList.c_____________________________________________ // COMPLETED

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

/*Creates a new empty list.
Returns the address of the list or NULL if fails.
Warning: calling this function on an initialized list can cause memory leaks, before calling this function second time you must use listPurge().
Important: you must always initialize a list with this function before use.*/
list listNew();

/*Inserts a new element into a list
To add a new element to the end of a list you must use List->Length as index.
Returns 0 on success and 1 on error.
Warning: if fails the insertion will be cancelled and the list remains intact.
Note: always resets the cache.*/
uint8 listInsert(list List, uint64 Index, void* Value);
/*Removes an element from a list at the given index.
Returns 0 on success and 1 on error.
Warning: if fails the List->Cache->Nodes will be NULL and the other values of the List->Cache will be 0.
Important: if the element to be removed is a pointer allocated with a malloc(), calloc() or realloc() it's recommended to call free() on it to avoid memory leaks, failures can lead to memory leaks.
Note: always resets the cache.*/
uint8 listRemove(list List, uint64 Index);

/*Returns the indexed node from a list.
You can get or set the value of the node with: Node->Value*/
listNode listGet(list List, uint64 Index);
/*Generates cache for a list.
Cacheing is recommended when a list is long enough to slow down the program.
Too few cacheing will make the list slower, too much cacheing will consume more memory.
NumberOfCachePoint: List->Length / CacheCoverage.
Returns 0 on success and 1 on error.
Warning: if fails the List->Cache->Nodes will be NULL and the other values of the List->Cache will be 0.
Important: failures can lead to memory leaks.*/
uint8 listCache(list List, uint64 CacheCoverage);

/*Deallocates a list from the memory with all of its elements.
Important: if the elements of the list were pointers allocated with a malloc(), calloc() or realloc() it's recommended to first call free() on those pointers to avoid memory leaks.
Note: it's recommended to set the List's value to NULL after calling this function, it's safe to pass a NULL value to this function.*/
uint8 listPurge(list List);

//____________________________________________NeoConvert.c___________________________________________ // COMPLETED

/*Converts a string to an unsigned integer.
You can check the success of the conversion by passing a logic variable
by reference, it's safe to pass NULL if error handling is not needed.
If it fails it will return a 0 as result.*/
uint64 STRtoUINT(char* Characters, logic* Success);
/*Converts an unsigned integer to a string.
The string will be deallocated and reinitialized, if the reinitialization fails the String->String will be NULL and the String->Length will be 0.
Returns 0 on success and 1 on error.*/
uint8 UINTtoSTR(uint64 Number, string String);

/*Converts a string to a signed integer.
You can check the success of the conversion by passing a logic variable
by reference, it's safe to pass NULL if error handling is not needed.
If it fails it will return a 0 as result.*/
sint64 STRtoSINT(char* Characters, logic* Success);
/*Converts a signed integer to a string.
The string will be deallocated and reinitialized, if the reinitialization fails the String->String will be NULL and the String->Length will be 0.
Returns 0 on success and 1 on error.*/
uint8 SINTtoSTR(sint64 Number, string String);

/*Converts a string to a double.
You can check the success of the conversion by passing a logic variable
by reference, it's safe to pass NULL if error handling is not needed.
If it fails it will return a 0 as result.*/
double STRtoDOUBLE(char* Characters, logic* Success);
/*Converts a double to a string.
The string will be deallocated and reinitialized, if the reinitialization fails the String->String will be NULL and the String->Length will be 0.
Returns 0 on success and 1 on error.*/
uint8 DOUBLEtoSTR(double Number, string String);

//_____________________________________________NeoFile.c_____________________________________________ // COMPLETED

/*Reads a text file and puts its lines into an array of strings.
Returns true on success and false on error.
Important: failures can lead to memory leaks.
Note: this function will not clear the values of the passed array, instead it will insert every line as a new string to the end of the array.*/
logic fileRead(char* FilePath, array Lines);
/*Writes the content of an array of strings line by line into a text file.
Returns true on success and false on error.
Note: every element of the passed array needs to a be a string.*/
logic fileWrite(array Lines, char* FilePath);