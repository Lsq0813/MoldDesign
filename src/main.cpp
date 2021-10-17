#include <iostream>
#include "product.h"
#include "dl_jww-copy.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cout<<"file path as parameter\n";
        return 1;
    }
    std::cout<<"MoldDesign start ...\n";
    product p;
    DL_Jww b;
    string file(argv[1]);
    b.in(file, &p);
    p.print();
    std::cout<<"MoldDesign end\n";
    return 0;
}

