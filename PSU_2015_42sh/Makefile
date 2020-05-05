##
## Makefile for lemin in /home/klein_h/Documents/rendu/CPE_2015_Lemin
## 
## Made by Arthur Klein
## Login   <klein_h@epitech.net>
## 
## Started on  Fri Apr 22 18:32:43 2016 klein_h
## Last update Sun Jun  5 21:28:49 2016 leroy_0
##

SRC_ERR		=	error/

SRC_MAIN	=	main/

SRC_PARS	=	parsing/

SRC_BUILT	=	built-in/

SRC_EXEC	=	exec/

SRC_EXECTREE	=	exec_tree/

SRC_CHECKTREE	=	check_tree/

SRC		=	$(SRC_EXECTREE)manage.c				\
			$(SRC_EXECTREE)left_redir.c			\
			$(SRC_EXECTREE)right_redir.c			\
			$(SRC_EXECTREE)seperator.c			\
			$(SRC_EXECTREE)pipe.c				\
			$(SRC_EXECTREE)exec_and_return_pipe.c		\
			$(SRC_CHECKTREE)check_tree.c			\
			$(SRC_ERR)error.c				\
			$(SRC_PARS)parsing.c				\
			$(SRC_PARS)node_func.c				\
			$(SRC_PARS)tree_func.c				\
			$(SRC_PARS)analyse_func.c			\
			$(SRC_PARS)split.c				\
			$(SRC_EXEC)exec.c				\
			$(SRC_BUILT)echo/echo.c				\
			$(SRC_BUILT)echo/echo_ptr_func.c		\
			$(SRC_BUILT)echo/echo_ptr_func_else.c		\
			$(SRC_BUILT)cd/cd.c				\
			$(SRC_BUILT)cd/cd_actions.c			\
			$(SRC_BUILT)env/env.c				\
			$(SRC_BUILT)unsetenv/my_unsetenv.c		\
			$(SRC_BUILT)setenv/my_setenv_tools.c		\
			$(SRC_BUILT)setenv/my_setenv.c			\
			$(SRC_BUILT)exit/exit.c				\
			$(SRC_EXEC)find_good_path.c			\
			$(SRC_EXEC)manage_built.c			\
			$(SRC_EXEC)put_error.c				\
			$(SRC_MAIN)prompt.c				\
			$(SRC_MAIN)main.c

BINPATH =		lib

NAME    =		42sh

CC      =		gcc $(INC)

RM      =		rm -f

LIB     =		-L$(BINPATH) -lmy

CFLAGS  +=		-W -Wall -Wextra

CFLAGS  +=		-I./include/

OBJS    =		$(SRC:.c=.o)


all     :		$(NAME)

$(NAME) :		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LIB)

lib	:		make -Clib

clean   :
			$(RM) $(OBJS)

fclean  :		clean
			$(RM) $(NAME)

re      :		fclean all

.PHONY  :		all clean fclean re
