#include "othello.h"

t_othello	g_othello;

static void	init(void)
{
	memset(g_othello.board, EMPTY, sizeof(g_othello.board));
	g_othello.turn = BLACK;
	g_othello.pass = FALSE;
	g_othello.board[3][4] = BLACK;
	g_othello.board[4][3] = BLACK;
	g_othello.board[3][3] = WHITE;
	g_othello.board[4][4] = WHITE;
	g_othello.board[2][3] = PLAYABLE;
	g_othello.board[3][2] = PLAYABLE;
	g_othello.board[4][5] = PLAYABLE;
	g_othello.board[5][4] = PLAYABLE;
	g_othello.turn = BLACK;
	print_status();
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
	glRasterPos2i(20, 20);
	glColor3d(0, 0, 0);
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
	if (g_othello.board[i][j] == PLAYABLE)
		update_board(i, j);
	display_stone();
	glFlush();
	print_status();
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
