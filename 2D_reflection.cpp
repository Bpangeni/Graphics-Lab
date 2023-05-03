#include <GL/glut.h>

float triangle[3][2] = { { -0.5, 0.0 }, { 0.5, 0.0 }, { 0.0, 0.5 } }; // Coordinates of the triangle

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0); // Blue color

    // Reflection matrix
    float reflectionMatrix[2][2] = { { 1, 0 }, { 0, -1 } };

    glLoadIdentity(); // Reset transformation matrix to identity matrix

    // Apply reflection matrix to each vertex of the triangle
    for (int i = 0; i < 3; i++) {
        float x = triangle[i][0];
        float y = triangle[i][1];
        triangle[i][0] = x * reflectionMatrix[0][0] + y * reflectionMatrix[0][1];
        triangle[i][1] = x * reflectionMatrix[1][0] + y * reflectionMatrix[1][1];
    }

    // Draw the reflected triangle
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
    glutCreateWindow("2D Reflection of Triangle");
    glClearColor(0.0, 0.0, 0.0, 0.0); // Black background color
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
