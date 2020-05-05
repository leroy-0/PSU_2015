##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_bistromathique
##
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
##
## Started on  Wed Oct 28 13:45:12 2015 maxime leroy
## Last update Sun Feb 21 18:46:48 2016 Tekm
##

CC=	gcc

RM=	rm -Rf

CFLAGS =	-Wextra -Wall

CFLAGS+=	-I./include

CLIENT=	client/client

SERVER=	server/server

SRCS_C=  src/my_strlen.c \
	 src/my_revstr.c \
	 src/my_putchar.c \
	 src/my_putstr.c \
	 src/my_put_nbr.c \
	 src/base.c \
	 src/my_strnbr.c \
	 src/my_getnbr.c \
	 src/client.c \
	 src/send_pid.c

SRCS_S=  src/my_strlen.c \
	 src/my_revstr.c \
	 src/my_putchar.c \
	 src/my_putstr.c \
	 src/my_put_nbr.c \
	 src/base.c \
	 src/my_getnbr.c \
	 src/server.c \
	 src/binary_convert.c

OBJS=	$(SRCS_C:.c=.o) $(SRCS_S:.c=.o)

all:	$(CLIENT) $(SERVER)

$(CLIENT):	$(OBJS)
	  mkdir client
	  $(CC) -o $(CLIENT) $(SRCS_C) $(CFLAGS)

$(SERVER): 	$(OBJS)
	  mkdir server
	  $(CC) -o $(SERVER) $(SRCS_S) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(CLIENT)
	$(RM) $(SERVER)
	$(RM) client
	$(RM) server

re:	fclean all

.PHONY:	all clean fclean re
