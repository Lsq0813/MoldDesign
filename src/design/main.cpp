#include <iostream>
#include "product.h"
#include "dl_jww-copy.h"

int main()
{
    std::cout<<"MoldDesign start ...\n";
    product p;
    DL_Jww b;
    string file("../dxf/circle.dxf");
    b.in(file, &p);
    p.print();
    std::cout<<"MoldDesign end\n";
    return 0;
}

