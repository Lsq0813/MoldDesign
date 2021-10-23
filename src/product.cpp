#include "product.h"
#include <iostream>

void Product::addCircle(const DL_CircleData& data)
{
    m_complist.add_circle(data);
}
