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

### NeoTypes* arrInsert(array Array, uint64 Index)
Inserts a new Element to the Array at the given Index.\
Returns the address of the new Element.\
The default value of the new Element is 0.\
Set the value of the new Element: arrInsert(Array, Index)->uInt = 10;

### uint8 arrRemove(array Array, uint64 Index)
Removes an element from the Array at the given Index.

### uint8 arrPurge(array Array)
Frees the Array from the memory with all of its Elements.\
It is safe to pass NULL to this function.

## NeoString.c

### uint64 strLength(char* Characters)
Returns the Length of the String (char*) with the '\0' included.

### string strNew()
Creates a new String, the String->String will be "\0" and the String->Length will be 1.\
Returns the address of the newly allocated String.\
You must initialize every String with this function before use.

### uint8 strInit(string String, char* Characters)
Replaces the String->String of the String with the given String (char*).

### uint8 strAppend(string String, char Character)
Appends the given Character to the end of the String.

### uint8 strConcat(string String, uint64 Count, char* Characters, ...)
Concatenates two or more Strings (char*) into one String.\
The number of the Strings (char*) to be concatenated must be accurate.

### uint8 strRead(string String)
Reads the content of standard input until '\n' and stores it in a String.

### uint8 strSplit(array Array, char* Characters, char Character)
Splits the String (char*) into an Array by the given Character.

### logic strCompare(char* Characters1, char* Characters2)
Compares two Strings (char*) Character by Character and returns true if they are equal or false if they differ.

### uint8 strPurge(string String)
Frees the String from the memory and its String->String value.\
It is safe to pass NULL to this function.

## NeoConvert.c

### uint64 STRtoUINT(char* Characters, logic* Success)
Converts the String to an Unsigned Integer.\
You can check the Success of the conversion by passing a Logic variable by reference, it is safe to pass NULL if error handling is not needed.\
If it fails it will return 0 as result.

### uint8 UINTtoSTR(uint64 Number, string String)
Converts an Unsigned Integer to String.\
Returns 0 on success or 1 on error.

### sint64 STRtoSINT(char* Characters, logic* Success)
Converts the String to a Signed Integer.\
You can check the Success of the conversion by passing a Logic variable by reference, it is safe to pass NULL if error handling is not needed.\
If it fails it will return 0 as result.

### uint8 SINTtoSTR(sint64 Number, string String)
Converts a Signed Integer to String.\
Returns 0 on success or 1 on error.

### double STRtoDOUBLE(char* Characters, logic* Success)
Converts the String to a Double.\
You can check the Success of the conversion by passing a Logic variable by reference, it is safe to pass NULL if error handling is not needed.\
If it fails it will return 0 as result.

### uint8 DOUBLEtoSTR(double Number, string String)
Converts a Double to String.\
Returns 0 on success or 1 on error.

## NeoFile.c

### logic fileRead(char* FilePath, array Lines)
Reads the content of a text file and puts its lines into an Array.\
Returns 0 on Success or 1 on Error.

### logic fileWrite(array Lines, char* FilePath)
Writes the content of an Array of Strings line by line into a text file.\
Returns 0 on Success or 1 on Error.

## NeoMemory.c

### void* memCopy(void* Source, uint64 Size)
Copies a block of memory.\
Returns the address of the copied memory or NULL if Size was 0.

### uint8 memCopyTo(void* Source, void* Destination, uint64 Size)
Copies a block of memory to the given Destination.\
You must preallocate the Destination to the correct Size.

### void* memLoad(char* FilePath, uint64 Size)
Loads data to the memory from a file.\
Returns the address of the loaded data or NULL if Size was 0.

### uint8 memLoadTo(char* FilePath, void* Destination, uint64 Size)
Loads data to the given Destination.\
You must preallocate the Destination to the correct Size.

### uint8 memSave(void* Source, uint64 Size, char* FilePath)
Saves data from the memory into a file.\
Returns 0 on Success or 1 on Error.