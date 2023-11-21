#include "NeoTypes.h"

uint64 STRtoUINT(char* Characters)
{
    uint64 result;

    result = 0;
    for (uint64 i = 0; i < strLength(Characters) - 1; i++)
    {
        result += (Characters[i] - '0') * pow(10, strLength(Characters) - 2 - i);
    }

    return result;
}
uint16 UINTtoSTR(string String, uint64 Number)
{
    free(String->String);
    free(String);

    uint64 i;

    String = strNew();

    for (i = 1; Number / i > 10; i *= 10);
    for (; i > 0; i /= 10)
    {
        strAppend(String, Number / i + '0');
        Number %= i;
    }

    return 0;
}

sint64 STRtoSINT(char* Characters)
{
    sint64 result;

    result = 0;
    for (uint64 i = 1; i < strLength(Characters) - 1; i++)
    {
        result += (Characters[i] - '0') * pow(10, strLength(Characters) - 2 - i);
    }

    if (Characters[0] == '-')
    {
        result *= -1;
    }
    else
    {
        result += (Characters[0] - '0') * pow(10, strLength(Characters) - 2);
    }

    return result;
}
uint16 SINTtoSTR(string String, sint64 Number)
{
    free(String->String);
    free(String);

    uint64 i;

    String = strNew();

    if (Number < 0)
    {
        Number *= -1;
        strAppend(String, '-');
    }

    for (i = 1; Number / i > 10; i *= 10);
    for (; i > 0; i /= 10)
    {
        strAppend(String, Number / i + '0');
        Number %= i;
    }

    return 0;
}

double STRtoDOUBLE(char* Characters)
{
    double result;

    uint64 decimal;

    result = 0;
    decimal = 0;
    for (uint64 i = 1; i < strLength(Characters) - 1; i++)
    {
        if (Characters[i] == '.' || Characters[i] == ',')
        {
            decimal = i;
            continue;
        }
        if (decimal)
        {
            result += (Characters[i] - '0') * pow(10, strLength(Characters) - 1 - i);
        }
        else
        {
            result += (Characters[i] - '0') * pow(10, strLength(Characters) - 2 - i);
        }
    }

    if (Characters[0] == '-')
    {
        result *= -1;
    }
    else
    {
        result += (Characters[0] - '0') * pow(10, strLength(Characters) - 2);
    }

    return result / pow(10, strLength(Characters) - 1 - decimal);
}

//1.55v
//155 / 100
//10 = 10 pow 2