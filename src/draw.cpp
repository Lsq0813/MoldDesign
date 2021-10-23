#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include "draw.h"

Draw *current;

Draw::Draw(const char *name, ComponentList *complistp)
{
    current = this;
    m_complistp = complistp;
    m_name = name;
}

void Draw::start()
{
    int argc = 0;
    char **argv = NULL;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(m_lenth , m_width);
    glutInitWindowPosition(100,150);
    glutCreateWindow(m_name);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
}

void Draw::init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-m_lenth,m_lenth,-m_width,m_width);
}

void Draw::display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for(auto it = current->m_complistp->m_components.begin(); it != current->m_complistp->m_components.end(); it++)
    {
        current->draw_componet(*it);
    }
    glFlush();
}

void Draw::draw_componet(Component &c)
{
    switch(c.m_type)
    {
        case Component::Type::e_circle:
             draw_circle((const DL_CircleData*)c.m_entities);
        case Component::Type::e_ring:
            draw_ring((const E_DL_RingData*)c.m_entities);
    }
}

void Draw::draw_circle(const DL_CircleData* data)
{
    glBegin(GL_POLYGON);
    glPointSize(m_penSize);
    int n = 3600;
    int x = data->cx;
    int y = data->cy;
    int r = data->radius;
    for(int i = 0; i < n; i++)
    {
        glVertex2d(x + r*cos(2*PI*i/n), y + r*sin(2*PI*i/n));
    }
    glEnd();
}

void Draw::draw_ring(const E_DL_RingData* data)
{
    glBegin(GL_LINE_STRIP);
    int n = 3600;
    int inx = data->ci.cx;
    int iny = data->ci.cy;
    int inr = data->ci.radius;
    int outx = data->co.cx;
    int outy = data->co.cy;
    int outr = data->co.radius;
    for(int i = 0; i < n; i++)
    {
        glVertex2d(outx + outr*cos(2*PI*i/n), outy + outr*sin(2*PI*i/n));
        glVertex2d(inx + inr*cos(2*PI*i/n), iny + inr*sin(2*PI*i/n));
    }
    glEnd();
}
