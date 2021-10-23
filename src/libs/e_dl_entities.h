#pragma once

#include "jwwlib/dl_entities.h"

struct E_DL_RingData
{
    E_DL_RingData(const DL_CircleData &i, const DL_CircleData &o)
    :ci(i.cx, i.cy, i.cz, i.radius), co(o.cx, o.cy, o.cz, o.radius){}
    DL_CircleData ci;
    DL_CircleData co;
};
