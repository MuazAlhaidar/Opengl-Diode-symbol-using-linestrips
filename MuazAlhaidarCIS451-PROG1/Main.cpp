// Author: Muaz Alhaidar

// Description: 
// Drawing a Diode Symbol, colouring the center red, 
// coloring the background white

// Date: 09/29/2019

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>

void myInit(void) {
	
	glClearColor(1.0, 1.0, 1.0, 0.0);                 // Set the background color to white 
	
	glLineWidth(2.0f);                                // Set line width to 2.0

	glMatrixMode(GL_PROJECTION);                      
	glLoadIdentity();
	gluOrtho2D(0.0f, 1.0f, 0.0f, 1.0f);               
}

/*
	Draws out 3 lines and a triangle (which is colored red)
	In order to represent a diode
*/
void displayDrawing(void) {

	glClear(GL_COLOR_BUFFER_BIT);                     // Clear the screen
	glColor3f(0.0f, 0.0f, 0.0f);                      // Set line color to black

	glBegin(GL_LINE_STRIP);                           // Cross at the front of the diode
	
		glVertex2f(0.25f, 0.5f);
		glVertex2f(0.4f, 0.5f);

		glVertex2f(0.4f, 0.6f); 
		glVertex2f(0.4f, 0.4f);

	glEnd();

	glBegin(GL_LINE_STRIP);                           // Line at the back of the diode

		glVertex2f(0.6f, 0.5f);
		glVertex2f(0.75f, 0.5f);
	
	glEnd();

	glBegin(GL_LINE_LOOP);                            // Line loops around the triangle
	
		glVertex2f(0.4f, 0.5f);
		glVertex2f(0.6f, 0.4);
		glVertex2f(0.6f, 0.6f);

	glEnd();

	glBegin(GL_TRIANGLES);

		glColor3f(1.0f, 0.0f, 0.0f);                  // Set colour to red

		glVertex2f(0.4f,0.5f);                        // Left Corner
		glVertex2f(0.6f,0.6f);                        // Top Corner
		glVertex2f(0.6f,0.4f);                        // Bottom Corner
	
	glEnd();

	glFlush();                                        // Send all output
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE);

	glutInitWindowSize(640, 480);                     // window size
	glutInitWindowPosition(200, 200);                 // distance from the top-left screen

	glutCreateWindow("Muaz Alhaidar PROG-1 Diode");   // message displayed on top bar window
	glutDisplayFunc(displayDrawing);                  // Display Triangle

	myInit();

	glutMainLoop();
	return 0;
}