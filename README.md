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