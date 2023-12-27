#include "NeoTypes.h"

uint64 asUINT(double Value)
{
    return *(uint64*)&Value;
}

sint64 asSINT(double Value)
{
    return *(sint64*)&Value;
}

double asDOUBLE(uint64 Value)
{
    return *(double*)&Value;
}