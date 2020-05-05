##
## Makefile for lib in /home/klein_h/Documents/rendu/CPE_2015_Lemin/lib
## 
## Made by Arthur Klein
## Login   <klein_h@epitech.net>
## 
## Started on  Sun Apr 24 22:32:38 2016 klein_h
## Last update Sun Jun  5 21:28:57 2016 leroy_0
##

LIBPATH =	my

SRCLIB  =	$(LIBPATH)/my_put_nbr.c		\
		$(LIBPATH)/my_getnbr.c		\
		$(LIBPATH)/my_putstr.c		\
		$(LIBPATH)/my_putchar.c		\
		$(LIBPATH)/my_strcmp.c		\
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

RM      =	rm -f

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
