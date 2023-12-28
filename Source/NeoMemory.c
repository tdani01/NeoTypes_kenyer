#include "NeoTypes.h"

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