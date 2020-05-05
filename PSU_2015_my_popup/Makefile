##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_bistromathique
## 
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
## 
## Started on  Wed Oct 28 13:45:12 2015 maxime leroy
## Last update Mon Nov 30 16:17:18 2015 leroy_0
##

CC =	gcc

RM =	rm -f

CFLAGS +=	-Wextra -Wall

#CFLAGS += -ansi -pedantic

CFLAGS +=	-I./include

LDFLAGS =	-L./lib/ -lmy -lncurses

NAME =	my_popup

SRCS =  my_popup.c

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
