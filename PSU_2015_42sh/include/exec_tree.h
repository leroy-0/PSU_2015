/*
** exec_tree.h for PSU_2015_42sh in /home/klein-h/rendu/PSU_2015_42sh/include/exec_tree.h
**
** Made by Arthur KLEIN
** Login   <arthur.klein@epitech.eu>
**
** Started on  Sat Jun 04 19:19:48 2016 Arthur KLEIN
** Last update Sun Jun  5 19:39:20 2016 Yan Poinssot
*/

#ifndef		EXEC_TREE_H_
# define	EXEC_TREE_H_

#include	"node.h"
typedef struct  s_return
  {
    int			ret;
    int			res;
  }               t_return;

int		check_below(t_tree *branch);
int		manage_redir_error(t_tree *branch);
int		check_redir(t_tree *branch);
int		manage(t_tree *branch, char ***env);
int		left_redir(t_tree *branch, char ***env);
int		left_dredir(t_tree *branch, char ***env);
int		right_redir(t_tree *branch, char ***env);
int		right_dredir(t_tree *branch, char ***env);
int		seperate(t_tree *branch, char ***env);
int		and(t_tree *branch, char ***env);
int		or(t_tree *branch, char ***env);
int		execute_right(int p_fd[2], int *fd, t_tree *tree, char ***env);
int		my_pipe(t_tree *branch, char ***env);
int		exec(char *line, char ***env, int pid, int *ret);
int		start_exec(t_tree *branch, char ***env);
int		execute_left(int p_fd[2], int fd, t_tree *tree, char ***env);
int		gest_error(t_tree *tree, int (*p_fd)[2], int pid);
int		exec_fork(char *line, char ***env, int pid, int *ret);

#endif		/* EXEC_TREE_H__ */
