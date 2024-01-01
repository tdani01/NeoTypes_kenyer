#include "NeoTypes.h"

void* memCopy(void* Source, uint64 Size)
{
    void* result;

    result = malloc(Size);
    if (result == NULL)
    {
        printf("memCopy(): Memory allocation failed\nParams: Source: %p, Size: %lld\n", Source, Size);
        exit(1);
    }

    memCopyTo(Source, result, Size);

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

    result = malloc(Size);
    if (result == NULL)
    {
        printf("memLoad(): Memory allocation failed\nParams: FilePath: %s, Size: %lld\n", FilePath, Size);
        exit(1);
    }

    if (memLoadTo(FilePath, result, Size) != 0)
    {
        return NULL;
    }

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

uint8 memSave(void* Source, uint64 Size, char* FilePath)
{
    FILE* file;

    file = fopen(FilePath, "w");
    if (file == NULL)
    {
        return 1;
    }

    for (uint64 i = 0; i < Size; i++)
    {
        fputc(((uint8*)Source)[i], file);
    }
    fclose(file);

    return 0;
}