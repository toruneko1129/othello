#include "othello.h"

static void	init(void)
{
	memset(othello.board, EMPTY, sizeof(othello.board));
	othello.board[3][4] = BLACK;
	othello.board[4][3] = BLACK;
	othello.board[3][3] = WHITE;
	othello.board[4][4] = WHITE;
	othello.turn = BLACK;
}

static void	setup_window(void)
{
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(SCREEN_POSX, SCREEN_POSY);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("othello");
	gluOrtho2D(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	glClearColor(0, 0.5, 0, 1);
}

void	display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	display_board();
	display_stone();
	glFlush();
}

void	mouse(int button, int state, int x, int y)
{
	int		i;
	int		j;

	if (x < 80 || x > 720 || y < 80 || y > 720 || button != GLUT_LEFT_BUTTON
		|| state != GLUT_DOWN)
		return ;
	i = x / 80 - 1;
	j = y / 80 - 1;
	if (othello.board[i][j] == EMPTY)
	{
		othello.board[i][j] = othello.turn;
		othello.turn = othello.turn % 2 + 1;
	}
	display_stone();
	glFlush();
}

int main(int argc, char **argv)
{
	init();
	glutInit(&argc, argv);
	setup_window();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
	return (EXIT_SUCCESS);
}
