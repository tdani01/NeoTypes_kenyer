#include "NeoTypes.h"

#define STRING_SIZE (sizeof(void*) + sizeof(uint64))

uint64 strLength(char* Characters)
{
    uint64 length;

    if (Characters == NULL)
    {
        return 0;
    }

    length = 0;
    while (Characters[length] != '\0')
    {
        length++;
    }

    return length + 1;
}

string strNew()
{
    string String;

    String = (string)malloc(STRING_SIZE);
    if (String == NULL)
    {
        return NULL;
    }

    String->String = (char*)malloc(sizeof(char) * 1);
    if (String->String == NULL)
    {
        free(String);
        return NULL;
    }
    String->String[0] = '\0';
    String->Length = 1;

    return String;
}

uint8 strInit(string String, char* Characters)
{   
    String->Length = strLength(Characters);
    free(String->String);
    String->String = (char*)malloc(sizeof(char) * String->Length);
    if (String->String == NULL)
    {
        String->Length = 0;
        return 1;
    }

    for (uint64 i = 0; i < String->Length; i++)
    {
        String->String[i] = Characters[i];
    }
    String->String[String->Length - 1] = '\0';

    return 0;
}

uint8 strAppend(string String, char Character)
{
    String->Length++;
    String->String = (char*)realloc(String->String, sizeof(char) * String->Length);
    if (String->String == NULL)
    {
        String->Length = 0;
        return 1;
    }
    String->String[String->Length - 2] = Character;
    String->String[String->Length - 1] = '\0';

    return 0;
}

uint8 strConcat(string String, uint64 Count, char* Characters, ...)
{
    char* StringTMP;
    uint64 StringLengthTMP;

    va_list CharactersArgs;
    uint64 current;
    char* CharactersTemp;

    va_start(CharactersArgs, Characters);
    StringLengthTMP = strLength(Characters) - 1;
    for (uint64 i = 1; i < Count; i++)
    {
        StringLengthTMP += strLength(va_arg(CharactersArgs, char*)) - 1;
    }
    StringLengthTMP++;
    va_end(CharactersArgs);

    StringTMP = (char*)malloc(sizeof(char) * StringLengthTMP);
    if (StringTMP == NULL)
    {
        return 1;
    }

    va_start(CharactersArgs, Characters);
    for (current = 0; current < strLength(Characters) - 1; current++)
    {
        StringTMP[current] = Characters[current];
    }
    for (uint64 i = 1; i < Count; i++)
    {
        CharactersTemp = va_arg(CharactersArgs, char*);
        for (uint64 j = 0; j < strLength(CharactersTemp) - 1; j++)
        {
            StringTMP[current] = CharactersTemp[j];
            current++;
        }
    }
    StringTMP[StringLengthTMP - 1] = '\0';
    va_end(CharactersArgs);

    free(String->String);
    String->String = StringTMP;
    String->Length = StringLengthTMP;

    return 0;
}

uint8 strRead(string String)
{
    char Character;

    free(String->String);
    String->String = (char*)malloc(sizeof(char) * 1);
    if (String->String == NULL)
    {
        String->Length = 0;
        return 1;
    }
    String->String[0] = '\0';
    String->Length = 1;

    while ((Character = getchar()) != '\n')
    {
        if (strAppend(String, Character) != 0)
        {
            return 1;
        }
    }

    return 0;
}

uint8 strSplit(array Array, char* Characters, char Character)
{
    array result;
    
    string StringTMP;

    result = arrNew(0);
    if (result == NULL)
    {
        return 1;
    }

    StringTMP = strNew();
    if (StringTMP == NULL)
    {
        return 1;
    }
    if (arrInsert(result, result->Length, StringTMP) != 0)
    {
        return 1;
    }

    for (uint64 i = 0; i < strLength(Characters) - 1; i++)
    {
        if (Characters[i] != Character)
        {
            if (strAppend((string)result->Values[result->Length - 1], Characters[i]) != 0)
            {
                return 1;
            }
        }
        else
        {
            if (strAppend((string)result->Values[result->Length - 1], '\0') != 0)
            {
                return 1;
            }
            StringTMP = strNew();
            if (StringTMP == NULL)
            {
                return 1;
            }
            if (arrInsert(result, result->Length, StringTMP) != 0)
            {
                return 1;
            }
        }
    }

    free(Array->Values);
    Array->Values = result->Values;
    Array->Length = result->Length;
    free(result);

    return 0;
}

logic strCompare(char* Characters1, char* Characters2)
{
    uint64 Characters1Length;

    Characters1Length = strLength(Characters1);
    if (Characters1Length == strLength(Characters2))
    {
        for (uint64 i = 0; i < Characters1Length; i++)
        {
            if (Characters1[i] != Characters2[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

uint8 strPurge(string String)
{
    if (String == NULL)
    {
        return 0;
    }

    free(String->String);
    free(String);

    return 0;
}