#include <GL/glut.h>
#include <math.h>

float triangle[3][2] = { { -0.5, 0.0 }, { 0.5, 0.0 }, { 0.0, 0.5 } }; // Coordinates of the triangle

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0); // Blue Color color

    // Rotation angle in degrees
    float angle = 45.0;

    // Convert angle from degrees to radians
    angle = angle * 3.14159265 / 180.0;

    // Rotation matrix
    float rotationMatrix[2][2] = { { cos(angle), -sin(angle) }, { sin(angle), cos(angle) } };

    glLoadIdentity(); // Reset transformation matrix to identity matrix

    // Apply rotation matrix to each vertex of the triangle
    for (int i = 0; i < 3; i++) {
        float x = triangle[i][0];
        float y = triangle[i][1];
        triangle[i][0] = x * rotationMatrix[0][0] + y * rotationMatrix[0][1];
        triangle[i][1] = x * rotationMatrix[1][0] + y * rotationMatrix[1][1];
    }

    // Draw the rotated triangle
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
    glutCreateWindow("2D Rotation of Triangle");
    glClearColor(0.0, 0.0, 0.0, 0.0); // Black background color
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
