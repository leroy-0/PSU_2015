/*
** exec_tree.h for exec_tree in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 18:50:05 2016 leroy_0
** Last update Sun Jun  5 21:13:13 2016 Yan Poinssot
*/

#ifndef		EXEC_TREE_H_
# define	EXEC_TREE_H_

#include	"node.h"

typedef struct		s_return
  {
    int			ret;
    int			res;
  }			t_return;

int		check_below(t_tree *branch);
int		check_redir(t_tree *branch);
int		manage_redir_error(t_tree *branch);
int		manage(t_tree *branch, char ***env);
int		left_redir(t_tree *branch, char ***env);
int		left_dredir(t_tree *branch, char ***env);
int		right_redir(t_tree *branch, char ***env);
int		right_dredir(t_tree *branch, char ***env);
int		seperate(t_tree *branch, char ***env);
int		and(t_tree *branch, char ***env);
int		or(t_tree *branch, char ***env);
int		my_pipe(t_tree *branch, char ***env);
int		exec(char *line, char ***env, int pid, int *ret);
int		start_exec(t_tree *branch, char ***env);
int		exec_fork(char *line, char ***env, int pid, int *ret);
char		*check_get_dredirl(t_tree *branch, char **env);
int		execute_left(int p_fd[2], int fd, t_tree *tree, char ***env);
int		execute_right(int p_fd[2], int *fd, t_tree *tree, char ***env);
int		gest_error(t_tree *tree, int (*p_fd)[2], int pid);

#endif		/* EXEC_TREE_H_ */
