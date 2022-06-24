NAME	=	othello
SRCDIR	=	./srcs
SRCLIST	=	main.c
SRCS	=	$(addprefix $(SRCDIR)/, $(SRCLIST))
OBJDIR	=	./objs
OBJS	=	$(SRCLIST:%.c=$(OBJDIR)/%.o)
INCLUDE	=	-I./includes
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LFLAGS	=	-lglut -lGLU -lGL -lm

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(INCLUDE) $(LFLAGS) -o $@

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
