#include "mold.h"

Mold::Mold(ComponentList *product)
{
    m_product = product;
}

void Mold::design()
{
   for(auto it = m_product->m_components.begin(); it != m_product->m_components.end(); it++) 
   {
       switch((*it).m_type)
       {
           case Component::Type::e_circle:
               design_circle((const DL_CircleData *)(*it).m_entities);
       }
   }
}

void Mold::design_circle(const DL_CircleData *data)
{
    DL_CircleData outcircle(data->cx, data->cy, data->cz, data->radius + 20);
    E_DL_RingData ring(*data, outcircle);
    m_mold.add_ring(ring);
}

