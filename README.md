# NeoTypes
A type library for C that contains: new variable names, bool, dynamic array, string, list, conversion between numeric and string types, casts between integer and floating point types. And a little file management too.

# Wiki

## NeoCast.c

### uint64 asInt(double Value)
Process a binary value stored in a double as an integer.

### double asDouble(uint64 Value)
Process a binary value stored in an integer as a double.

## NeoArray.c

### array arrNew(uint64 Length)
Creates a new array with the given length.\
Returns the address of the array or NULL if fails.\
Warning: calling this function on an initialized array can cause memory leaks, before calling this function second time you must use arrPurge().\
Important: you must always initialize an array with this function before use.

### uint8 arrInit(array Array, uint64 Length, void* Values, ...)
Clears the elements of the given array and initializes it with the new ones.\
Returns 0 on success and 1 on error.\
Warning: if fails the Array->Values will be NULL and the Array->Length will be 0.\
Important: if the previous elements of the array were pointers allocated with a malloc(), calloc() or realloc() it's recommended to first call free() on those pointers to avoid memory leaks.\
Note: this function can not replace the arrNew() function.

### uint8 arrInsert(array Array, uint64 Index, void* Value)
Inserts a new element into an array.\
To add a new element to the end of an array you must use Array->Length as index.\
Returns 0 on success and 1 on error.\
Warning: if fails the Array->Values will be NULL and the Array->Length will be 0.\
Important: failures can lead to memory leaks.

### uint8 arrRemove(array Array, uint64 Index)
Removes an element from an array at the given index.\
Returns 0 on success and 1 on error.\
Warning: if fails the Array->Values will be NULL and the Array->Length will be 0.\
Important: if the element to be removed is a pointer allocated with a malloc(), calloc() or realloc() it's recommended to call free() on it to avoid memory leaks, failures can lead to memory leaks.

### uint8 arrPurge(array Array)
Deallocates an array from the memory with all of its elements.\
Important: if the elements of the array were pointers allocated with a malloc(), calloc() or realloc() it's recommended to first call free() on those pointers to avoid memory leaks.\
Note: it's recommended to set the Array's value to NULL after calling this function, it's safe to pass a NULL value to this function.

## NeoString.c

### uint64 strLength(char* Characters)
Returns the length of a string (char*) with the '\0' included.

### string strNew()
Creates a new string, the String->String will be "\0" and the String->Length will be 1.\
Returns the address of the string or NULL if fails.\
Warning: calling this function on an initialized string can cause memory leaks, before calling this function second time you must use strPurge().\
Important: you must always initialize a string with this function before use.

### uint8 strInit(string String, char* Characters)
Clears the string of the given string and initializes it with the new one.\
Returns 0 on success and 1 on error.\
Warning: if fails the String->String will be NULL and the String->Length will be 0.\
Note: this function can not replace the strNew() function.

### uint8 strAppend(string String, char Character)
Appends a new character to the end of the string.\
Returns 0 on success and 1 on error.\
Warning: if fails the String->String will be NULL and the String->Length will be 0.\
Important: failures can lead to memory leaks.

### uint8 strConcat(string String, uint64 Count, char* Characters, ...)
Concatenates two or more strings into one string.\
Returns 0 on success and 1 on error.\
Important: the number of the strings will be concatenated must be accurate.\
Note: deallocating the target string is not needed, if fails every string will remain intact.

### uint8 strRead(string String)
Reads the contents of standard input until '\n' and stores it in a string.\
Returns 0 on success and 1 on error.\
Warning: if fails the String->String will be NULL and the String->Length will be 0.\
Important: failures can lead to memory leaks.

### uint8 strSplit(array Array, char* Characters, char Character)
Splits a string into an array of strings by the given character.\
You can access a particular string from the array: ((string)Array->Values[index])->String.\
Returns 0 on success and 1 on error.\
Warning: if fails the result array may be broken and must be fixed manually using arrPurge() and arrNew().\
Important: failures can lead to memory leaks.

### logic strCompare(char* Characters1, char* Characters2)
Compares two strings character by character and returns true if they are equal.

### uint8 strPurge(string String)
Deallocates a string from the memory.\
Note: it's recommended to set the String's value to NULL after calling this function, it's safe to pass a NULL value to this function.

### uint8 strPurgeKeepString(string String, char** Characters)
Deallocates a string from the memory, but keeps the char* of the purged string.\
Example use case: if you want to return only a char* from a function, but not the string itself.\
Note: it's recommended to set the String's value to NULL after calling this function, it's safe to pass a NULL value to this function.

## NeoList.c

### list listNew()
Creates a new empty list.\
Returns the address of the list or NULL if fails.\
Warning: calling this function on an initialized list can cause memory leaks, before calling this function second time you must use listPurge().\
Important: you must always initialize a list with this function before use.

### uint8 listInsert(list List, uint64 Index, void* Value)
Inserts a new element into a list.\
To add a new element to the end of a list you must use List->Length as index.\
Returns 0 on success and 1 on error.\
Warning: if fails the insertion will be cancelled and the list remains intact.\
Note: always resets the cache.

### uint8 listRemove(list List, uint64 Index)
Removes an element from a list at the given index.\
Returns 0 on success and 1 on error.\
Warning: if fails the List->Cache->Nodes will be NULL and the other values of the List->Cache will be 0.\
Important: if the element to be removed is a pointer allocated with a malloc(), calloc() or realloc() it's recommended to call free() on it to avoid memory leaks, failures can lead to memory leaks.\
Note: always resets the cache.

### listNode listGet(list List, uint64 Index)
Returns the indexed node from a list.\
You can get or set the value of the node with: Node->Value.

### uint8 listCache(list List, uint64 CacheCoverage)
Generates cache for a list.\
Cacheing is recommended when a list is long enough to slow down the program.\
Too few cacheing will make the list slower, too much cacheing will consume more memory.\
NumberOfCachePoint: List->Length / CacheCoverage.\
Returns 0 on success and 1 on error.\
Warning: if fails the List->Cache->Nodes will be NULL and the other values of the List->Cache will be 0.\
Important: failures can lead to memory leaks.

### int8 listPurge(list List)
Deallocates a list from the memory with all of its elements.\
Important: if the elements of the list were pointers allocated with a malloc(), calloc() or realloc() it's recommended to first call free() on those pointers to avoid memory leaks.\
Note: it's recommended to set the List's value to NULL after calling this function, it's safe to pass a NULL value to this function.

## NeoConvert.c

### uint64 STRtoUINT(char* Characters, logic* Success)
Converts a string to an unsigned integer.\
You can check the success of the conversion by passing a logic variable
by reference, it's safe to pass NULL if error handling is not needed.\
If it fails it will return a 0 as result.

### uint8 UINTtoSTR(uint64 Number, string String)
Converts an unsigned integer to a string.\
The string will be deallocated and reinitialized, if the reinitialization fails the String->String will be NULL and the String->Length will be 0.\
Returns 0 on success and 1 on error.

### sint64 STRtoSINT(char* Characters, logic* Success)
Converts a string to a signed integer.\
You can check the success of the conversion by passing a logic variable
by reference, it's safe to pass NULL if error handling is not needed.\
If it fails it will return a 0 as result.

### uint8 SINTtoSTR(sint64 Number, string String)
Converts a signed integer to a string.\
The string will be deallocated and reinitialized, if the reinitialization fails the String->String will be NULL and the String->Length will be 0.\
Returns 0 on success and 1 on error.

### double STRtoDOUBLE(char* Characters, logic* Success)
Converts a string to a double.\
You can check the success of the conversion by passing a logic variable
by reference, it's safe to pass NULL if error handling is not needed.\
If it fails it will return a 0 as result.

### uint8 DOUBLEtoSTR(double Number, string String)
Converts a double to a string.\
The string will be deallocated and reinitialized, if the reinitialization fails the String->String will be NULL and the String->Length will be 0.\
Returns 0 on success and 1 on error.

## NeoFile.c

### logic fileRead(char* FilePath, array Lines)
Reads a text file and puts its lines into an array of strings.\
Returns true on success and false on error.\
Important: failures can lead to memory leaks.\
Note: this function will not clear the values of the passed array, instead it will insert every line as a new string to the end of the array.

### logic fileWrite(array Lines, char* FilePath)
Writes the content of an array of strings line by line into a text file.\
Returns true on success and false on error.\
Note: every element of the passed array needs to a be a string.