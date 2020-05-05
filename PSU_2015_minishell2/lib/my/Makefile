##
## Makefile for Makefile in
##
## Made by leroy_0
## Login   <leroy_0@epitech.net>
##
## Started on  Thu Apr 21 10:30:17 2016 leroy_0
## Last update Thu Apr 21 10:30:22 2016 leroy_0
##

NAME	= libmy.a

SRC	= my_putchar.c \
	  my_isneg.c \
	  my_put_nbr.c \
	  my_swap.c \
	  my_putstr.c \
	  my_strlen.c \
	  my_getnbr.c \
	  my_power_rec.c \
	  my_square_root.c \
	  my_is_prime.c \
	  my_find_prime_sup.c \
	  my_strcpy.c \
	  my_strncpy.c \
	  my_revstr.c \
	  my_strstr.c \
	  my_strcmp.c \
	  my_strncmp.c \
	  my_strupcase.c \
	  my_strlowcase.c \
	  my_strcapitalize.c \
	  my_str_isalpha.c \
	  my_str_isnum.c \
	  my_str_islower.c \
	  my_str_isupper.c \
	  my_str_isprintable.c \
	  my_strcat.c \
	  my_strnbr.c \
	  base.c \
	  my_strunnbr.c \
	  my_strnbput.c \
	  my_strprintS.c \
	  my_main.c \
	  my_printf.c \
	  my_strint.c \
	  my_display.c \
	  my_getnbrchar.c

OBJ	= $(SRC:.c=.o)

CFLAGS  = -I../../include/

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp libmy.a ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
