##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_bistromathique
## 
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
## 
## Started on  Wed Oct 28 13:45:12 2015 maxime leroy
## Last update Thu Dec 10 10:29:42 2015 leroy_0
##

CC =	gcc

RM =	rm -f

CFLAGS +=	-Wextra -Wall

#CFLAGS += -ansi -pedantic

CFLAGS +=	-I./include

LDFLAGS =	-L./lib/ -lmy -lncurses

NAME =	my_select

SRCS =  my_select.c \
	my_del.c \
	my_disp.c \
	my_key.c

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
