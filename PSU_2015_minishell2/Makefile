##
## Makefile for Makefile in
##
## Made by leroy_0
## Login   <leroy_0@epitech.net>
##
## Started on  Thu Apr 21 10:29:19 2016 leroy_0
## Last update Thu Apr 21 10:29:24 2016 leroy_0
##

LIBPATH	=	lib/

SRC 	=	src/allo.c \
		src/displ.c \
		src/other.c \
		src/prealloc.c \
		src/finder.c \
		src/opts.c \
		src/main.c \
		src/main2.c \
		src/epur_str.c \
		src/pipe.c \
		src/pipe2.c \
		src/pipe3.c \
		src/pipe4.c \
		src/redir.c \
		src/redir2.c \
		src/my_x_malloc.c \
		src/check.c \
		src/get_next_line.c

SRCLIB	=	lib/my/my_putchar.c \
		lib/my/my_isneg.c \
		lib/my/my_put_nbr.c \
		lib/my/my_swap.c \
		lib/my/my_putstr.c \
		lib/my/my_strlen.c \
		lib/my/my_getnbr.c \
		lib/my/my_power_rec.c \
		lib/my/my_square_root.c \
		lib/my/my_is_prime.c \
		lib/my/my_find_prime_sup.c \
		lib/my/my_strcpy.c \
		lib/my/my_strncpy.c \
		lib/my/my_revstr.c \
		lib/my/my_strstr.c \
		lib/my/my_strcmp.c \
		lib/my/my_strncmp.c \
		lib/my/my_strupcase.c \
		lib/my/my_strlowcase.c \
		lib/my/my_strcapitalize.c \
		lib/my/my_str_isalpha.c \
		lib/my/my_str_isnum.c \
		lib/my/my_str_islower.c \
		lib/my/my_str_isupper.c \
		lib/my/my_str_isprintable.c \
		lib/my/my_strcat.c \
		lib/my/my_strnbr.c \
		lib/my/base.c \
		lib/my/my_strunnbr.c \
		lib/my/my_strnbput.c \
		lib/my/my_strprintS.c \
		lib/my/my_main.c \
		lib/my/my_printf.c \
		lib/my/my_strint.c \
		lib/my/my_display.c \
		lib/my/my_getnbrchar.c

NAME_LIB=	lib/libmy.a

ARRC	=	ar rc

RANLIB	=	ranlib

OBJ 	= 	$(SRC:.c=.o)
OBJLIB 	= 	$(SRCLIB:.c=.o)

NAME	=	mysh

CFLAGS	=	-W -Wall -Wextra -g

CFLAGS	+=	-I include/

LIB	=	-L./lib/ -lmy

RM 	= 	rm -Rf

CC	=	 gcc

all	:	$(NAME)

lib	:	$(NAME_LIB)

$(NAME_LIB) : 	$(OBJLIB)
		$(ARRC) $(NAME_LIB) $(OBJLIB)
		$(RANLIB) $(NAME_LIB)


$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean	:
		$(RM) $(OBJ) $(OBJLIB)

fclean	: 	clean
		$(RM) $(NAME)

re	:	clean lib all

.PHONY: all lib clean fclean re
