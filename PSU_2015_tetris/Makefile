##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_bistromathique
## 
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
## 
## Started on  Wed Oct 28 13:45:12 2015 maxime leroy
## Last update Sun Mar 20 19:39:41 2016 Tekm
##

CC =	gcc

RM =	rm -f

CFLAGS +=	-Wextra -Wall -W -g

CFLAGS +=	-I./include

LDFLAGS =	-lncurses

NAME =	tetris

SRCS =  src/tetris.c \
	src/check_tetrimino.c \
	src/checks.c \
	src/checker.c \
	src/my_putstr.c \
	src/my_putchar.c \
	src/my_put_nbr.c \
	src/my_revstr.c \
	src/my_strlen.c \
	src/my_strcpy.c \
	src/my_strcat.c \
	src/my_strcmp.c \
	src/my_strint.c \
	src/my_strncmp.c \
	src/my_strnbr.c \
	src/get_next_line.c \
	src/my_ptr_fnct.c \
	src/my_ptr_fnct2.c \
	src/my_opt_key.c\
	src/display.c \
	src/my_parsing.c \
	src/check_all.c \
	src/show_print.c \
	src/getxy.c \
	src/get_check.c \
	src/my_ptr_fnct3.c \
	src/space_and_seq.c \
	src/manage_my_win.c \
	src/manage_my_win2.c \
	src/manage_my_win3.c \
	src/malloc_init.c

OBJS =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	  $(CC) -o $(NAME) $(SRCS) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
