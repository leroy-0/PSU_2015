##
## Makefile for Makefile in /home/leroy_0/rendu/Piscine_C_J10
## 
## Made by maxime leroy
## Login   <leroy_0@epitech.net>
## 
## Started on  Fri Oct  9 09:38:11 2015 maxime leroy
## Last update Sun Nov 15 19:31:30 2015 root
##

NAME	= libmy.a

SRC	= my_putchar.c \
	  my_isneg.c \
	  my_put_nbr.c \
	  my_swap.c \
	  my_putstr.c \
	  my_strlen.c \
	  my_getnbr.c \
	  my_sort_int_tab.c \
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
	  my_showstr.c \
	  my_showmem.c \
	  my_strcat.c \
	  my_strncat.c \
	  my_strnbr.c \
	  base.c \
	  my_strunnbr.c \
	  my_strnbput.c \
	  my_strprintS.c \
	  my_main.c \
	  my_printf.c \
	  my_strint.c \
	  my_display.c

OBJ	= $(SRC:.c=.o)

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
