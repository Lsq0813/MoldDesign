#pragma once

#include "component.h"

class Mold
{
public:
    Mold(ComponentList *product);
    ~Mold() {}
    void design();    
    void design_circle(const DL_CircleData *data);

public:
    ComponentList m_mold; 

private:
    ComponentList *m_product;
};

