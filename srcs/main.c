#include "othello.h"

static void	setup_window(void)
{
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(SCREEN_POSX, SCREEN_POSY);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Othello");
	gluOrtho2D(0, 800, 800, 0);
	glClearColor(0, 0.5, 0, 1);
}

void	display(void)
{
	int		i;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3d(0.0, 0.0, 0.0);
	glLineWidth(3);
	glBegin(GL_LINES);
	i = -1;
	while (++i <= BOARD_SIZE)
	{
		glVertex2i(80 + 80 * i, 720);
		glVertex2i(80 + 80 * i, 80);
		glVertex2i(80, 80 + 80 * i);
		glVertex2i(720, 80 + 80 * i);
	}
	glEnd();
	glColor3d(0.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2i(240, 240);
	glVertex2i(240, 560);
	glVertex2i(560, 240);
	glVertex2i(560, 560);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	setup_window();
	glutDisplayFunc(display);
	glutMainLoop();
	return (EXIT_SUCCESS);
}
