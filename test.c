#include "NeoTypes.h"

int main()
{
    string str = strNew();
    strRead(str);

    DOUBLEtoSTR(STRtoDOUBLE(str->String, NULL), str);

    printf("%s %ld\n", str->String, strLength(str->String));

    return 0;
}