#pragma once

#include "product.h"
#include "jwwlib/dl_entities.h"
#include "e_dl_entities.h"

class Draw
{
public:
    Draw(const char *name, ComponentList *complistp); 
    ~Draw() {}
    void start();
    void init();
    static void display();

private:
    void draw_componet(Component &c);
    void draw_circle(const DL_CircleData* data);
    void draw_ring(const E_DL_RingData* data);

private:
    ComponentList *m_complistp;

    //graphic
    const char* m_name;
    int m_lenth = 600;
    int m_width = 480;
    float m_penSize = 10.0;

    //math
    const float PI = 3.1415926;
};

