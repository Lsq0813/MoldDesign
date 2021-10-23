#include "component.h"

void ComponentList::add_circle(const DL_CircleData &data)
{
    DL_CircleData *ndata = new DL_CircleData(data.cx, data.cy, data.cz, data.radius);
    Component c(Component::Type::e_circle, ndata);
    m_components.push_back(c);
}

void ComponentList::add_ring(const E_DL_RingData &data)
{
    E_DL_RingData *ndata = new E_DL_RingData(data.ci, data.co);
    Component c(Component::Type::e_ring, ndata);
    m_components.push_back(c);
}
