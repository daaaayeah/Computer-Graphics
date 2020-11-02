#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float r = 1.0;
float g = 1.0;
float b = 1.0;

int startMovement;
float mouseCurPositionX;
float mouseCurPositionY;

void init();
void mydisplay();
void mouseStatus(int button, int state, int x, int y);
void mouseMove(int x, int y);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

	glutInitWindowSize(500, 500);

	glutInitWindowPosition(0, 0);

	glutCreateWindow("18011600_이다예");

	glutDisplayFunc(mydisplay);
	glutMouseFunc(mouseStatus);
	glutMotionFunc(mouseMove); // 능동 모션(버튼 누른 채)
	
	init();

	glutMainLoop();
}

void init() {
	glClearColor(1.0, 1.0, 0.0, 1.0); // Yellow Background

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0); // Screen Size
}
void mydisplay() {
	glClear(GL_COLOR_BUFFER_BIT); // clear the window

	glColor3f(r, g, b); // White Polygons

	glBegin(GL_POLYGON);
	glVertex2f(-70.0, -70.0);
	glVertex2f(-70.0, -20.0);
	glVertex2f(70.0, -20.0);
	glVertex2f(70.0, -70.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-80.0, 20.0);
	glVertex2f(-20.0, 80.0);
	glVertex2f(-20.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(20.0, 80.0);
	glVertex2f(60.0, 80.0);
	glVertex2f(80.0, 40.0);
	glVertex2f(40.0, 0.0);
	glVertex2f(0.0, 40.0);
	glEnd();

	glutSwapBuffers();
}
void mouseStatus(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		startMovement = GL_TRUE;
	mouseCurPositionX = x;
	mouseCurPositionY = y;
}
void mouseMove(int x, int y) {
	if (x > mouseCurPositionX)
		r = 1.0, g = 0.0, b = 0.0;
	else if (x < mouseCurPositionX)
		r = 0.0, g = 1.0, b = 0.0;
	mouseCurPositionX = x;
	mouseCurPositionY = y;
	glutPostRedisplay();
}