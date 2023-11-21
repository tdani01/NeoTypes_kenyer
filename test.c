#include "NeoTypes.h"

int main()
{
    string str = strNew();
    strRead(str);
    double a = STRtoDOUBLE(str->String, NULL);
    DOUBLEtoSTR(a, str);
    printf("%lf\n", a);
    printf("%lf %ld\n", STRtoDOUBLE(str->String, NULL), strLength(str->String));

    return 0;
}