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

typedef enum t_state
{
	EMPTY,
	BLACK,
	WHITE
}	e_state;

typedef struct s_othello
{
	char	board[BOARD_SIZE][BOARD_SIZE];
}	t_othello;

//display.c
void	display_board(void);
void	display_stone(void);

t_othello	othello;

#endif
