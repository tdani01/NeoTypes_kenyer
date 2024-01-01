#include "NeoTypes.h"

uint8 fileRead(char* FilePath, array Lines)
{
    FILE* file;
    string line;
    char character;

    if (FilePath == NULL)
    {
        printf("fileRead(): FilePath must not be NULL\nParams: FilePath: %s, Lines: %p\n", FilePath, Lines);
        exit(1);
    }
    if (Lines == NULL)
    {
        printf("fileRead(): Lines must not be NULL\nParams: FilePath: %s, Lines: %p\n", FilePath, Lines);
        exit(1);
    }

    Lines->Values = realloc(Lines->Values, 0);
    Lines->Length = 0;

    file = fopen(FilePath, "r");
    if (file == NULL)
    {
        return 1;
    }

    line = strNew();

    while (!feof(file))
    {
        character = fgetc(file);

        if (character != '\n')
        {
            strAppend(line, character);
        }
        else
        {
            arrInsert(Lines, Lines->Length)->String = line;
            line = strNew();
        }
    }

    strPurge(line);
    fclose(file);

    return 0;
}

uint8 fileWrite(array Lines, char* FilePath)
{
    FILE* file;

    if (Lines == NULL)
    {
        printf("fileWrite(): Lines must not be NULL\nParams: Lines: %p, FilePath: %s\n", Lines, FilePath);
        exit(1);
    }
    if (FilePath == NULL)
    {
        printf("fileWrite(): FilePath must not be NULL\nParams: Lines: %p, FilePath: %s\n", Lines, FilePath);
        exit(1);
    }

    file = fopen(FilePath, "w");
    if (file == NULL)
    {
        return 1;
    }

    for (uint64 i = 0; i < Lines->Length; i++)
    {
        fprintf(file, "%s\n", Lines->Values[i].String->String);
    }
    fclose(file);

    return 0;
}