##
## Makefile for lib in /home/leroy_0/tek1/PSU_2015_42sh/bonus
##
## Made by leroy_0
## Login   <leroy_0@epitech.net>
##
## Started on  Sun Jun  5 18:59:00 2016 leroy_0
## Last update Sun Jun  5 22:55:47 2016 bruere_s
##

LIBPATH =	my

SRCLIB  =	$(LIBPATH)/my_put_nbr.c		\
		$(LIBPATH)/my_getnbr.c		\
		$(LIBPATH)/my_putstr.c		\
		$(LIBPATH)/my_putchar.c		\
		$(LIBPATH)/my_strcmp.c		\
		$(LIBPATH)/my_strlen_car.c	\
		$(LIBPATH)/my_strcpy.c		\
		$(LIBPATH)/my_strncmp.c		\
		$(LIBPATH)/my_revstr.c		\
		$(LIBPATH)/my_strdup.c		\
		$(LIBPATH)/my_str_to_wordtab.c	\
		$(LIBPATH)/my_strcat.c		\
		$(LIBPATH)/my_strlen.c		\
		$(LIBPATH)/my_puterr.c		\
		$(LIBPATH)/my_strcut.c		\
		$(LIBPATH)/my_itoa.c		\
		$(LIBPATH)/epur_str.c		\
		$(LIBPATH)/epur_quote.c		\
		$(LIBPATH)/epur_virgule.c	\
		$(LIBPATH)/my_x_malloc.c	\
		$(LIBPATH)/get_next_line.c	\
		$(LIBPATH)/my_tablen.c		\
		$(LIBPATH)/tab_to_str.c		\
		$(LIBPATH)/stitch.c		\
		$(LIBPATH)/extract.c		\
		$(LIBPATH)/send_err.c

NAME    =	libmy.a

ARRC    =	ar rc

RANLIB  =	ranlib

RM      =	rm -Rf

CFLAGS  +=	-W -Wall -Wextra

CFLAGS  +=	-I ../include/

OBJ     =	$(SRCLIB:.c=.o)

OBJS    =	$(SRC:.c=.o)

all     :	$(NAME)

$(NAME) :	$(OBJ)
		$(ARRC) $(NAME) $(OBJ)
		$(RANLIB) $(NAME)

clean   :
		$(RM) $(OBJ)

fclean  :	clean
		$(RM) $(NAME)

re      :	fclean all

.PHONY  :	all clean fclean re
