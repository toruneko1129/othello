#include "othello.h"

const int	g_dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int	g_dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

static t_bool	is_turnable(int x, int y, int dir) 
{
	int		nx;
	int		ny;

	nx = x + g_dx[dir];
	ny = y + g_dy[dir];
	if (nx < 0 || nx >= BOARD_SIZE || ny < 0 || ny >= BOARD_SIZE
		|| g_othello.board[nx][ny] != (g_othello.turn ^ 1))
		return (FALSE);
	while (1)
	{
		nx += g_dx[dir];
		ny += g_dy[dir];
		if (nx < 0 || nx >= BOARD_SIZE || ny < 0 || ny >= BOARD_SIZE
			|| g_othello.board[nx][ny] == EMPTY
			|| g_othello.board[nx][ny] == PLAYABLE)
			return (FALSE);
		else if (g_othello.board[nx][ny] == g_othello.turn)
			return (TRUE);
	}
	return (FALSE);
}

static void	turn_stone(int x, int y, int dir)
{
	int		nx;
	int		ny;

	nx = x + g_dx[dir];
	ny = y + g_dy[dir];
	while (0 <= nx && nx < BOARD_SIZE && 0 <= ny && ny < BOARD_SIZE
		&& g_othello.board[nx][ny] == (g_othello.turn ^ 1))
	{
		g_othello.board[nx][ny] = g_othello.turn;
		nx += g_dx[dir];
		ny += g_dy[dir];
	}
}

void	update_board(int x, int y)
{
	int		dir;

	g_othello.board[x][y] = g_othello.turn;
	dir = -1;
	while (++dir < 8)
		if (is_turnable(x, y, dir))
			turn_stone(x, y, dir);
	g_othello.turn ^= 1;
}
