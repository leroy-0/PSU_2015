/*
** redir2.c for redir2 in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:07:10 2016 leroy_0
** Last update Thu Apr 21 10:07:17 2016 leroy_0
*/

#include "my.h"
#include "mysh.h"
#include "struct.h"
#include "structure.h"
#include "get_next_line.h"

void		my_redir_rightdouble(t_struct_d *data, char ***cmds)
{
  int	pid;
  int	out;

  out = 0;
  pid = fork();
  if (pid == 0)
    run_redir_rd(data, cmds, out);
  else if (pid < 0)
    {
      my_putstr("Error : fork has failed\n");
      return;
    }
  else
    wait(NULL);
}

char		*get_text(char *res, char *tmp, char *str)
{
  if (res)
    {
      tmp = my_x_malloc(sizeof(char) * (my_strlen(res) + my_strlen(str) + 2));
      tmp = my_strcpy(tmp, res);
      tmp = my_strcat(tmp, str);
      tmp = my_strcat(tmp, "\n");
      res = my_x_malloc(sizeof(char) * (my_strlen(tmp) + 2));
      res = my_strcpy(res, tmp);
    }
  else
    {
      res = my_x_malloc(sizeof(char) * (my_strlen(str) + 2));
      res = my_strcpy(res, str);
      res = my_strcat(res, "\n");
    }
  return (res);
}

void		exec_redir_ldouble(t_struct_d *data, char *str, char ***cmds)
{
  char		*res;
  char		*tmp;
  int		tmpfd[2];

  res = NULL;
  tmp = NULL;
  my_putstr("> ");
  while (my_strncmp((str = get_next_line(0)),
		    cmds[1][0], my_strlen(cmds[1][0])) != 0)
    {
      my_putstr("> ");
      res = get_text(res, tmp, str);
    }
  pipe(tmpfd);
  write(tmpfd[0], res, my_strlen(res));
  write(tmpfd[1], res, my_strlen(res));
  dup2(tmpfd[0], 0);
  close(tmpfd[0]);
  close(tmpfd[1]);
  my_find(data, cmds[0]);
  if (execve(data->thisenv, cmds[0], data->tmpenv) < 0)
    {
      my_putstr("Error : execve failed\n");
      exit(1);
    }
}

void		my_redir_leftdouble(t_struct_d *data, char *str, char ***cmds)
{
  int		pid;

  (void)data;
  (void)str;
  pid = fork();
  if (pid == 0)
    exec_redir_ldouble(data, str, cmds);
  else if (pid < 0)
    {
      my_putstr("Error : fork has failed\n");
      return;
    }
  else
    wait(NULL);
}
