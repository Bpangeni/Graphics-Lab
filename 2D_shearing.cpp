#include <GL/glut.h>

float triangle[3][3] = { { -0.5, 0.0, 1.0 }, { 0.5, 0.0, 1.0 }, { 0.0, 0.5, 1.0 } }; // Coordinates of the triangle 

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0); // Blue color

    // Shearing matrix
    float shearingMatrix[3][3] = { { 1, 0.5, 0 }, { 0.5, 1, 0 }, { 0, 0, 1 } };

    glLoadIdentity(); // Reset transformation matrix to identity matrix

    // Apply shearing matrix to each vertex of the triangle
    for (int i = 0; i < 3; i++) {
        float x = triangle[i][0];
        float y = triangle[i][1];
        float w = triangle[i][2];
        triangle[i][0] = x * shearingMatrix[0][0] + y * shearingMatrix[0][1] + w * shearingMatrix[0][2];
        triangle[i][1] = x * shearingMatrix[1][0] + y * shearingMatrix[1][1] + w * shearingMatrix[1][2];
        triangle[i][2] = x * shearingMatrix[2][0] + y * shearingMatrix[2][1] + w * shearingMatrix[2][2];
    }

    // Draw the sheared triangle
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++) {
        glVertex2f(triangle[i][0] / triangle[i][2], triangle[i][1] / triangle[i][2]);
    }
    glEnd();

    glFlush(); // Render the graphics
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Shearing of Triangle with Homogeneous Coordinates");
    glClearColor(0.0, 0.0, 0.0, 0.0); // Black background color
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
