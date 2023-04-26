#include <iostream>
#include <GL/glut.h>

using namespace std;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500, 500, -500, 500);
}

void drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawCircle(int xc, int yc, int r)
{
    int p = 1 - r;
    int x = 0;
    int y = r;
    while (x < y)
    {
        if (p < 0)
        {
            x++;
            p += 2 * x + 1;
        }
        else
        {
            x++;
            y--;
            p += 2 * (x - y) + 1;
        }
        /*The drawPixel(int x, int y) function uses OpenGL's glBegin() and glEnd() functions
         to draw a single pixel at the specified coordinates (x,y) using glVertex2i().*/
        drawPixel(xc + x, yc + y);
        drawPixel(xc + x, yc - y);
        drawPixel(xc - x, yc + y);
        drawPixel(xc - x, yc - y);
        drawPixel(xc + y, yc + x);
        drawPixel(xc + y, yc - x);
        drawPixel(xc - y, yc + x);
        drawPixel(xc - y, yc - x);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    drawCircle(0, 0, 200);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
