#include <iostream>
#include "jwwlib/dl_jww-copy.h"
#include "draw.h"
#include "component.h"
#include "product.h"
#include "mold.h"
#include "unistd.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        std::cout<<"file path as parameter\n";
        return 1;
    }
    string file(argv[1]);

    Product p;
    DL_Jww b;
    b.in(file, &p);

    Mold m(&(p.m_complist));
    m.design();

    int pid = fork();
    if(pid == 0)
    {
        Draw d1("mold", &(m.m_mold));
        d1.start();
    }
    else
    {
        Draw d2("product", &(p.m_complist));
        d2.start();
    }
    return 0;
}
