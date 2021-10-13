#include "dl_jww-copy.h"
#include "dl_creationinterfacechild.h"

int main()
{
    DL_CreationInterfaceChild a;
    DL_Jww b;
    string file("../../../../dxf/circle.dxf");
    b.in(file, &a);
    return 0;
}

