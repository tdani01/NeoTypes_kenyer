#include "NeoTypes.h"

int main()
{
    string str = strNew();
    strRead(str);

    printf("%lf %d\n", STRtoDOUBLE(str->String), strLength(str->String));

    return 0;
}