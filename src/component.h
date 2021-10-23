#pragma once

#include <vector>
#include "jwwlib/dl_entities.h"
#include "e_dl_entities.h"

struct Component
{
    enum Type
    {
        e_circle,
        e_ring
    };
    Type m_type;
    void *m_entities;
    Component(Type t, void *e):m_type(t), m_entities(e){}
};

class ComponentList
{
public:
    void add_circle(const DL_CircleData &data);
    void add_ring(const E_DL_RingData &data);
public:
     std::vector<Component> m_components;
};

