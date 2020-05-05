/*
** left_dredir.c for left_dredir in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 18:45:02 2016 leroy_0
** Last update Sun Jun  5 18:49:22 2016 leroy_0
*/

#include        <fcntl.h>
#include        <sys/types.h>
#include        <stdio.h>
#include        <stdlib.h>
#include        <unistd.h>
#include        <fcntl.h>
#include        <string.h>
#include        "get_next_line.h"
#include        "exec_tree.h"
#include        "bonus.h"
#include        "exec.h"
#include        "node.h"
#include        "my.h"

int		left_dredir(t_tree *branch, char ***env)
{
  char		*res;
  int		save;
  int		result;
  int		tmpfd[2];

  result = 0;
  if ((res = check_get_dredirl(branch, *env)) == NULL)
    return (1);
  pipe(tmpfd);
  if (res != NULL && res[0] != '\0')
    write(tmpfd[1], res, strlen(res));
  close(tmpfd[1]);
  save = dup(0);
  dup2(tmpfd[0], 0);
  result = 0;
  if (branch->left->node->func != NULL)
    return (manage(branch->left, env));
  result = exec_fork(branch->left->node->line, env, 0, &result);
  close(tmpfd[0]);
  dup2(save, 0);
  return (result);
}
