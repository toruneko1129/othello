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
			if (g_othello.board[i][j] == EMPTY)
				glColor3d(0, 0.5, 0);
			else if (g_othello.board[i][j] == PLAYABLE)
				glColor3d(1, 1, 0);
			else if (g_othello.board[i][j] == BLACK)
				glColor3d(0, 0, 0);
			else if (g_othello.board[i][j] == WHITE)
				glColor3d(1, 1, 1);
			glBegin(GL_POINTS);
			glVertex2i(120 + 80 * i, 120 + 80 * j);
			glEnd();
		}
	}
}

void	print_status(void)
{
	int		cnt[4];
	int		i;
	int		j;

	memset(cnt, 0, sizeof(cnt));
	printf("Turn: ");
	if (g_othello.turn == BLACK)
		printf("Black\n");
	else
		printf("White\n");
	i = -1;
	while (++i < BOARD_SIZE)
	{
		j = -1;
		while (++j < BOARD_SIZE)
			++cnt[(int)g_othello.board[i][j]];
	}
	printf("Black: %d\nWhite: %d\n", cnt[BLACK], cnt[WHITE]);
	if (cnt[PLAYABLE] == 0)
	{
		printf("Result: ");
		if (cnt[BLACK] > cnt[WHITE])
			printf("Black win\n");
		else if (cnt[BLACK] < cnt[WHITE])
			printf("White win\n");
		else
			printf("Draw\n");
	}
	printf("\n");
}
