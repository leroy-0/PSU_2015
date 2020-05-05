##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_bistromathique
## 
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
## 
## Started on  Wed Oct 28 13:45:12 2015 maxime leroy
## Last update Sun Nov 15 19:56:22 2015 leroy_0
##

CC =	gcc

RM =	rm -f

CFLAGS +=	-Wextra -Wall

#CFLAGS += -ansi -pedantic

CFLAGS +=	-I./include

LDFLAGS =	-L./lib/ -lmy

NAME =	libmy.a

SRCS = 	lib/my/my_main.c \
	lib/my/my_printf.c \
	lib/my/my_strprintS.c \
	lib/my/base.c \
	lib/my/my_strnbr.c \
	lib/my/my_strunnbr.c \
	lib/my/my_putstr.c \
	lib/my/my_strlen.c \
	lib/my/my_putchar.c \
	lib/my/my_revstr.c \
	lib/my/my_strcat.c \
	lib/my/my_strint.c \
	lib/my/my_display.c

OBJS =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc  $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
