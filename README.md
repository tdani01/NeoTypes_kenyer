# NeoTypes
A type library for C that contains: new variable names, bool, dynamic array, string, conversion between numeric and string types. And a little memory/file management too.

# Wiki

## NeoArray.c

### array arrNew(uint64 Length)
Creates a new Array with the given Length.\
Returns the address of the newly allocated Array.\
You must initialize every Array with this function before use!

### NeoTypes* arrElement(array Array, uint64 Index)
Returns an Element from the Array at the given Index.\
Assign a value to an Element: arrElement(Array, Index)->uInt = 10;\
Get a value from an Element: uint8 a = arrElement(Array, Index)->uInt;

### uint8 arrInsert(array Array, uint64 Index, void* Value)
Inserts a new Element to the Array at the given Index.\
Returns the address of the new Element.\
The default value of the new Element is 0.\
Set the value of the new Element: arrInsert(Array, Index)->uInt = 10;

### uint8 arrRemove(array Array, uint64 Index)
Removes an element from the Array at the given Index.

### uint8 arrPurge(array Array)
Frees the Array from the memory with all of its Elements.

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

## NeoMemory.c

### void* memCopy(void* Source, uint64 Size)
Copies a block of memory.\
Returns the address of the copied memory or NULL if the source is NULL or fails.
