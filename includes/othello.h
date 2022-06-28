#ifndef OTHELLO_H
# define OTHELLO_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
//version3.1
# include <GL/glut.h>

//screen settings
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 800
# define SCREEN_POSX 100
# define SCREEN_POSY 100

# define BOARD_SIZE 8

typedef int	t_bool;

typedef enum e_state
{
	EMPTY,
	PLAYABLE,
	BLACK,
	WHITE
}	t_state;

typedef enum e_boolean
{
	FALSE,
	TRUE
}	t_boolean;

typedef struct s_othello
{
	char	board[BOARD_SIZE][BOARD_SIZE];
	char	turn;
}	t_othello;

extern t_othello	g_othello;

//display.c
void	display_board(void);
void	display_stone(void);

//update_board.c
void	update_board(int x, int y);


#endif
