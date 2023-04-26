#include <GL/glut.h>
#include <iostream>

using namespace std;

int x_center = 300, y_center = 300, a = 200, b = 100;

void plot_ellipse_points(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x_center + x, y_center + y);
    glVertex2i(x_center - x, y_center + y);
    glVertex2i(x_center + x, y_center - y);
    glVertex2i(x_center - x, y_center - y);
    glEnd();
}

void draw_ellipse()
{
    int x = 0, y = b;
    double a_sqr = a * a, b_sqr = b * b;
    double d = b_sqr - a_sqr * b + a_sqr * 0.25;
    double fx = 2 * b_sqr * x, fy = 2 * a_sqr * y;

    plot_ellipse_points(x, y);

    while (fx < fy)
    {
        x++;
        fx += 2 * b_sqr;

        if (d < 0)
        {
            d += fx + b_sqr;
        }
        else
        {
            y--;
            fy -= 2 * a_sqr;
            d += fx - fy + b_sqr;
        }
        /*The plot_ellipse_points(int x, int y) function uses OpenGL's glBegin() and glEnd() functions
         to draw a set of four points in each quadrant of the ellipse using glVertex2i().
        The function takes in the coordinates (x,y) and adds the offsets from the center
        coordinates to plot the points in the correct location.*/
        plot_ellipse_points(x, y);
    }

    double tmp1 = (x + 0.5) * (x + 0.5);
    double tmp2 = (y - 1) * (y - 1);
    d = b_sqr * tmp1 + a_sqr * tmp2 - a_sqr * b_sqr;

    while (y > 0)
    {
        y--;
        fy -= 2 * a_sqr;

        if (d >= 0)
        {
            d += a_sqr - fy;
        }
        else
        {
            x++;
            fx += 2 * b_sqr;
            d += fx - fy + a_sqr;
        }

        plot_ellipse_points(x, y);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    draw_ellipse();

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Midpoint Ellipse Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
