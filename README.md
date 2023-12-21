# NeoTypes
A type library for C that contains: new variable names, bool, dynamic array, string, list, conversion between numeric and string types, casts between integer and floating point types. And a little file management too.

# Wiki

## NeoCast.c

### uint64 asInt(double Value);
Process a binary value stored in a double as an integer.

### double asDouble(uint64 Value);
Process a binary value stored in an integer as a double.

## NeoArray.c

### array arrNew(uint64 Length);
Creates a new array with the given length.\
Returns the address of the array or NULL if fails.\
Warning: calling this function on an initialized array can cause memory leaks, before calling this function second time you must use arrPurge().\
Important: you must always initialize an array with this function before use.\

### uint8 arrInit(array Array, uint64 Length, void* Values, ...);
Clears the elements of the given array and initializes it with the new ones.\
Returns 0 on success and 1 on error.\
Warning: if fails the Array->Values will be NULL and the Array->Length will be 0.\
Important: if the previous elements of the array were pointers allocated with a malloc(), calloc() or realloc() it's recommended to first call free() on those pointers to avoid memory leaks.\
Note: this function can not replace the arrNew() function.

### uint8 arrInsert(array Array, uint64 Index, void* Value);
Inserts a new element into an array.\
To add a new element to the end of an array you must use Array->Length as index.\
Returns 0 on success and 1 on error.\
Warning: if fails the Array->Values will be NULL and the Array->Length will be 0.\
Important: failures can lead to memory leaks.