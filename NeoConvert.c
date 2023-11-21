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
uint16 UINTtoSTR(uint64 Number, string String)
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
uint16 SINTtoSTR(sint64 Number, string String)
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

    decimal = strLength(Characters) - 1;
    for (uint64 i = 0; i < strLength(Characters) - 1; i++)
    {
        if (Characters[i] == '.' || Characters[i] == ',')
        {
            decimal = i;
            break;
        }
    }

    result = 0;
    for (uint64 i = 1; i < decimal; i++)
    {
        result += (Characters[i] - '0') * pow(10, decimal - 1 - i);
    }
    for (uint64 i = decimal + 1; i < strLength(Characters) - 1; i++)
    {
        result += (Characters[i] - '0') * 1 / pow(10, i - decimal);
    }

    if (Characters[0] == '-')
    {
        result *= -1;
    }
    else
    {
        result += (Characters[0] - '0') * pow(10, decimal - 1);
    }

    return result;
}
uint16 DOUBLEtoSTR(double Number, string String)
{
    free(String->String);
    free(String);

    uint64 i, whole;
    double fraction;

    String = strNew();

    if (Number < 0)
    {
        Number *= -1;
        strAppend(String, '-');
    }

    whole = (uint64)trunc(Number);
    fraction = Number - whole;
    for (i = 1; whole / i > 10; i *= 10);
    for (; i > 0; i /= 10)
    {
        strAppend(String, whole / i + '0');
        whole %= i;
    }
    if (fraction > 0)
    {
        strAppend(String, '.');

        for (i = 0; fraction * pow(10, i) / 10 < 1; i++); //BROKEN
        fraction *= pow(10, i);

        for (i = 1; (uint64)round(fraction) / i > 10; i *= 10);
        for (; i > 0; i /= 10)
        {
            strAppend(String, (uint64)round(fraction) / i + '0');
            fraction = (uint64)round(fraction) % i;
        }
    }

    return 0;
}