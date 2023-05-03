#include <GL/glut.h>

float triangle[3][2] = { { -0.5, 0.0 }, { 0.5, 0.0 }, { 0.0, 0.5 } }; // Coordinates of the triangle

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0); // Blue color

    // Scaling factors
    float sx = 1.15;
    float sy = 1.15;

    glLoadIdentity(); // Reset transformation matrix to identity matrix

    // Apply scaling factors to each vertex of the triangle
    for (int i = 0; i < 3; i++) {
        triangle[i][0] *= sx;
        triangle[i][1] *= sy;
    }

    // Draw the scaled triangle
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(triangle[i][0], triangle[i][1]);
    }
    glEnd();

    glFlush(); // Render the graphics
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Scaling of Triangle");
    glClearColor(0.0, 0.0, 0.0, 0.0); // Black background color
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
