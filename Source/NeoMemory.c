#include "NeoTypes.h"

uint8 memAlloc(void** PTR, uint64 Size)
{
    if (Size == 0)
    {
        *PTR = NULL;
        return 0;
    }

    *PTR = malloc(Size);
    if (*PTR == NULL)
    {
        return 1;
    }

    return 0;
}

uint8 memCalloc(void** PTR, uint64 Size)
{
    uint64 i;

    if (Size == 0)
    {
        *PTR = NULL;
        return 0;
    }

    *PTR = malloc(Size);
    if (*PTR == NULL)
    {
        return 1;
    }

    for (i = 0; i < Size / sizeof(uint64); i++)
    {
        ((uint64*)*PTR)[i] = 0;
    }
    for (i *= sizeof(uint64); i < Size; i++)
    {
        ((uint8*)*PTR)[i] = 0;
    }

    return 0;
}

uint8 memRealloc(void** PTR, uint64 Size)
{
    void* tmp;

    if (Size == 0)
    {
        free(*PTR);
        *PTR = NULL;
        return 0;
    }

    tmp = realloc(*PTR, Size);
    if (tmp == NULL)
    {
        return 1;
    }
    *PTR = tmp;

    return 0;
}

uint8 memFree(void** PTR)
{
    free(*PTR);
    *PTR = NULL;
    return 0;
}

void* memCopy(void* Source, uint64 Size)
{
    void* result;

    uint64 i;

    if (memAlloc(&result, Size) != 0)
    {
        return NULL;
    }

    for (i = 0; i < Size / sizeof(uint64); i++)
    {
        ((uint64*)result)[i] = ((uint64*)Source)[i];
    }
    for (i *= sizeof(uint64); i < Size; i++)
    {
        ((uint8*)result)[i] = ((uint8*)Source)[i];
    }

    return result;
}

uint8 memCopyTo(void* Source, void* Destination, uint64 Size)
{
    uint64 i;

    for (i = 0; i < Size / sizeof(uint64); i++)
    {
        ((uint64*)Destination)[i] = ((uint64*)Source)[i];
    }
    for (i *= sizeof(uint64); i < Size; i++)
    {
        ((uint8*)Destination)[i] = ((uint8*)Source)[i];
    }

    return 0;
}

void* memLoad(char* FilePath, uint64 Size)
{
    void* result;

    FILE* file;

    file = fopen(FilePath, "r");
    if (file == NULL)
    {
        return NULL;
    }

    if (memAlloc(&result, Size) != 0)
    {
        fclose(file);
        return NULL;
    }

    for (uint64 i = 0; i < Size; i++)
    {
        ((uint8*)result)[i] = fgetc(file);
    }
    fclose(file);

    return result;
}

uint8 memLoadTo(char* FilePath, void* Destination, uint64 Size)
{
    FILE* file;

    file = fopen(FilePath, "r");
    if (file == NULL)
    {
        return 1;
    }

    for (uint64 i = 0; i < Size; i++)
    {
        ((uint8*)Destination)[i] = fgetc(file);
    }
    fclose(file);

    return 0;
}

uint8 memSave(void* Area, uint64 Size, char* FilePath)
{
    FILE* file;

    file = fopen(FilePath, "w");
    if (file == NULL)
    {
        return 1;
    }

    for (uint64 i = 0; i < Size; i++)
    {
        fputc(((uint8*)Area)[i], file);
    }
    fclose(file);

    return 0;
}