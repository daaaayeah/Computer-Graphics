#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

void init();
void mydisplay();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("18011600_이다예");
	glutDisplayFunc(mydisplay);
	init();
	glutMainLoop();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 1.0); // background
	//glColor3f(1.0, 0.0, 1.0); // color
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // glOrtho2D(X)
}
void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 1.0); // color
	glVertex2f(-0.5, -0.5);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.0, 0.5);
	glVertex2f(0.0, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0); // color
	glVertex2f(0.1, -0.5);
	glVertex2f(0.1, 0.5);
	glVertex2f(0.5, 0.5);
	glEnd();

	glFlush(); // FrameBuffer -> 화면
}