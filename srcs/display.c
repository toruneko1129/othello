#include "othello.h"

void	display_board(void)
{
	int		i;

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
}

void	display_stone(void)
{
	int		i;
	int		j;

	glPointSize(60);
	i = -1;
	while (++i < BOARD_SIZE)
	{
		j = -1;
		while (++j < BOARD_SIZE)
		{
			if (othello.board[i][j] != BLACK
				&& othello.board[i][j] != WHITE)
				continue ;
			if (othello.board[i][j] == BLACK)
				glColor3d(0, 0, 0);
			if (othello.board[i][j] == WHITE)
				glColor3d(1, 1, 1);
			glBegin(GL_POINTS);
			glVertex2i(120 + 80 * i, 120 + 80 * j);
			glEnd();
		}
	}
}
