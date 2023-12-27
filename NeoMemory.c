#include "NeoTypes.h"

void* neoCopy(void* Source, uint64 Size)
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
        ((char*)result)[i] = ((char*)Source)[i];
    }

    return result;
}