#include "NeoTypes.h"
#include <stdio.h>

void* memCopy(void* Source, uint64 Size)
{
    void* result;

    if (Source == NULL)
    {
        return NULL;
    }

    result = malloc(Size);
    if (result == NULL)
    {
        return NULL;
    }

    for (uint64 i = 0; i < Size; i++)
    {
        ((uint8*)result)[i] = ((uint8*)Source)[i];
    }

    return result;
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

    result = malloc(Size);
    if (result == NULL)
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

logic memSave(void* Area, uint64 Size, char* FilePath)
{
    FILE* file;

    file = fopen(FilePath, "w");
    if (file == NULL)
    {
        return false;
    }

    for (uint64 i = 0; i < Size; i++)
    {
        fputc(((uint8*)Area)[i], file);
    }
    fclose(file);

    return true;
}