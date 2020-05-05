##
## Makefile for bonus in /home/leroy_0/tek1/PSU_2015_42sh/bonus
##
## Made by leroy_0
## Login   <leroy_0@epitech.net>
##
## Started on  Sun Jun  5 18:59:14 2016 leroy_0
## Last update Sun Jun  5 23:24:14 2016 bruere_s
##

SRC_ERR		=	error/

SRC_MAIN	=	main/

SRC_PARS	=	parsing/

SRC_BUILT	=	built-in/

SRC_EXEC	=	exec/

SRC_EXECTREE	=	exec_tree/

SRC_TERMCAPS	=	termcaps/

SRC_AUTO_C	=	auto_complete/

SRC_HISTORY	=	history/

SRC_CHECKTREE	=	check_tree/

SRC_ALIAS	=	alias/

SRC_GLOBING	=	globing/

SRC_ASCII	=	ascii/

SRC		=	$(SRC_ASCII)ascii.c				\
			$(SRC_EXECTREE)manage.c				\
			$(SRC_EXECTREE)left_redir.c			\
			$(SRC_EXECTREE)right_redir.c			\
			$(SRC_EXECTREE)seperator.c			\
			$(SRC_EXECTREE)exec_and_return_pipe.c		\
			$(SRC_EXECTREE)pipe.c				\
			$(SRC_EXECTREE)left_dredir.c			\
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
			$(SRC_BUILT)echo/echo_special_func.c		\
			$(SRC_BUILT)echo/echo_special_func_else.c	\
			$(SRC_BUILT)cd/cd.c				\
			$(SRC_BUILT)cd/cd_actions.c			\
			$(SRC_BUILT)env/env.c				\
			$(SRC_BUILT)unsetenv/my_unsetenv.c		\
			$(SRC_BUILT)setenv/my_setenv_tools.c		\
			$(SRC_BUILT)setenv/my_setenv.c			\
			$(SRC_BUILT)exit/exit.c				\
			$(SRC_BUILT)alias/my_alias.c			\
			$(SRC_EXEC)find_good_path.c			\
			$(SRC_EXEC)manage_built.c			\
			$(SRC_EXEC)change_local_variable.c		\
			$(SRC_EXEC)change_variable_history.c		\
			$(SRC_EXEC)put_error.c				\
			$(SRC_TERMCAPS)key_actions.c			\
			$(SRC_TERMCAPS)reset_screen.c			\
			$(SRC_TERMCAPS)key_move.c			\
			$(SRC_TERMCAPS)key_others.c			\
			$(SRC_TERMCAPS)key_ctrls.c			\
			$(SRC_TERMCAPS)key_ctrl_w.c			\
			$(SRC_TERMCAPS)key_init_ptrs.c			\
			$(SRC_TERMCAPS)key_direction.c			\
			$(SRC_HISTORY)add_in_history.c			\
			$(SRC_HISTORY)arrow_hist.c			\
			$(SRC_HISTORY)previous_envent.c			\
			$(SRC_HISTORY)aff_history.c			\
			$(SRC_HISTORY)start_history.c			\
			$(SRC_ALIAS)alias.c				\
			$(SRC_ALIAS)check_good_alias.c			\
			$(SRC_GLOBING)globing.c				\
			$(SRC_AUTO_C)auto_complete.c			\
			$(SRC_AUTO_C)auto_complete_func.c		\
			$(SRC_AUTO_C)display.c				\
			$(SRC_AUTO_C)find.c				\
			$(SRC_AUTO_C)find_new.c				\
			$(SRC_AUTO_C)save_paths.c			\
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
			$(CC) -o $(NAME) $(OBJS) $(LIB) -lncurses

lib	:		make -Clib

clean   :
			$(RM) $(OBJS)

fclean  :		clean
			$(RM) $(NAME)

re      :		fclean all

.PHONY  :		all clean fclean re
