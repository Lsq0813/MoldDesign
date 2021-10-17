#include "product.h"
#include <iostream>

const char *component_name [] = {"circle"};

void product::addCircle(const DL_CircleData& data)
{
    component c(CircleData, &data);
    components.push_back(c);
}

void product::print()
{
    int i = 0;
    for(auto it = components.begin(); it != components.end(); it++)
    {
        i++;
        std::cout<<i<<": "<<component_name[it->type]<<"\n";
    }
}
