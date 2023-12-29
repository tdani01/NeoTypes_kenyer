#include "Source/NeoTypes.h"

sint32 main(sint32 argc, char* *argv)
{
    array file;

    file = arrNew(0);
    fileRead("test.txt", file);

    for (uint8 i = 0; i < file->Length; i++)
    {
        printf("%s\n", ((string)file->Values[i])->String);
    }

    return 0;
}