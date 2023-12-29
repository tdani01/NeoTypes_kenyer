#include "NeoTypes.h"

uint8 fileRead(char* FilePath, array Lines)
{
    FILE* file;
    string line;
    char character;

    free(Lines->Values);
    Lines->Values = NULL;
    Lines->Length = 0;

    file = fopen(FilePath, "r");
    if (file == NULL)
    {
        return 1;
    }

    line = strNew();
    if (line == NULL)
    {
        fclose(file);
        return 1;
    }

    while (!feof(file))
    {
        character = fgetc(file);

        if (character != '\n')
        {
            if (strAppend(line, character) != 0)
            {
                free(line);
                fclose(file);

                for (uint64 i = 0; i < Lines->Length; i++)
                {
                    strPurge(Lines->Values[i]);
                }

                return 1;
            }
        }
        else
        {
            if (arrInsert(Lines, Lines->Length, line) != 0)
            {
                strPurge(line);
                fclose(file);
                return 1;
            }
            
            line = strNew();
            if (line == NULL)
            {
                fclose(file);

                for (uint64 i = 0; i < Lines->Length; i++)
                {
                    strPurge(Lines->Values[i]);
                }

                return 1;
            }
        }
    }

    strPurge(line);
    fclose(file);

    return 0;
}

uint8 fileWrite(array Lines, char* FilePath)
{
    FILE* file;

    file = fopen(FilePath, "w");
    if (file == NULL)
    {
        return 1;
    }

    for (uint64 i = 0; i < Lines->Length; i++)
    {
        fprintf(file, "%s\n", ((string)Lines->Values[i])->String);
    }
    fclose(file);

    return 0;
}