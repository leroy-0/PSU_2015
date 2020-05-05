/*
** exec_and_return_pipe.c for PSU_2015_42sh in /home/klein-h/exec_tree/exec_and_return_pipe.c
**
** Made by Arthur KLEIN
** Login   <arthur.klein@epitech.eu>
**
** Started on  Sun Jun 05 19:08:25 2016 Arthur KLEIN
** Last update Sun Jun  5 23:20:52 2016 bruere_s
*/

#include	<sys/wait.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"exec_tree.h"
#include	"node.h"
#include	"exec.h"
#include	"my.h"

int		execute_left(int p_fd[2], int fd, t_tree *tree, char ***env)
{
  int		ret;

  ret = 0;
  if (tree->left != NULL)
    {
      dup2(p_fd[1], 1);
      close(p_fd[0]);
      dup2(fd, 0);
      if (tree->left->node->func == NULL)
	ret = exec(tree->left->node->line, env, 0, &ret);
      else
	ret = tree->left->node->func(tree->left, env);
      close(p_fd[1]);
      close(fd);
      exit(0);
    }
  return (ret);
}

int		execute_right(int p_fd[2], int *fd, t_tree *tree, char ***env)
{
  int		ret;

  close(p_fd[1]);
  ret = 0;
  *fd = p_fd[0];
  if (tree->right != NULL)
    {
      dup2(p_fd[0], 0);
      ret = manage(tree->right, env);
    }
  return (ret);
}

int		gest_error(t_tree *tree, int (*p_fd)[2], int pid)
{
  if (tree->right != NULL)
    pid = pipe(*p_fd);
  if (pid == -1)
    {
      my_putstr("Error : pipe failed\n");
      return (1);
    }
  return (0);
}
