#include "NeoTypes.h"

int main()
{
    string str = strNew();
    strRead(str);
    //SINTtoSTR(STRtoSINT(str->String), str);
    boolean Success;
    printf("%lf %ld\n", STRtoDOUBLE(str->String), strLength(str->String));
    //printf("%d\n", Success);

    return 0;
}