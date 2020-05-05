/*
** other.c for other in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:29:40 2016 leroy_0
** Last update Thu Apr 21 10:42:55 2016 leroy_0
*/

#include "my.h"
#include "mysh.h"
#include "structure.h"
#include "get_next_line.h"

int		my_finder(t_struct_d *data, char **arg)
{
  int		fd;

  fd = -1;
  if (arg[0] && ((fd = open(arg[0], O_RDONLY)) != -1))
    {
      close(fd);
      data->thisenv = my_x_malloc(sizeof(char) * my_strlen(arg[0]) + 1);
      my_strcpy(data->thisenv, arg[0]);
    }
  else if (arg && arg[0] && arg[0][0] == '.' && arg[0][1] == '.')
    return (-1);
  else
    fd = my_finder_antes(data, arg, fd);
  return (fd);
}

int		my_find(t_struct_d *data, char **arg)
{
  int		fd;

  fd = my_finder(data, arg);
  if (fd == -1)
    {
      my_putstr(arg[0]);
      my_putstr(" : Unable to find the command\n");
    }
  return (fd);
}

void		my_get_args(t_struct_d *data, char *str)
{
  int			a;
  int			b;

  a = 0;
  b = 0;
  data->nbarg = 0;
  data->args = my_x_malloc(sizeof(char *) * (my_strlen(str) + 1));
  while (str && str[a] != '\0')
    {
      data->args[data->nbarg] = my_x_malloc(sizeof(char) * my_strlen(str) + 1);
      a = my_whil(data, a, b, str);
      data->nbarg++;
      b = 0;
      if (str[a] != '\0')
	a++;
    }
  data->args[data->nbarg] = NULL;
}

char		**my_get_newenv(t_struct_d *data, int a, int b)
{
  char	**newenv;

  while (data->tmpenv && data->tmpenv[a])
    a++;
  newenv = my_x_malloc(sizeof(char *) * a + 1);
  a = 0;
  while (data->tmpenv && data->tmpenv[a])
    {
      newenv[b] = my_x_malloc(sizeof(char) * (my_strlen(data->tmpenv[a]) + 1));
      if (data->args[1] && s_cmp(data->args[1], data->tmpenv[a]) != 1)
	{
	  my_strcpy(newenv[b], data->tmpenv[a]);
	  b++;
	}
      a++;
    }
  newenv[a - 1] = NULL;
  return (newenv);
}

void		my_unsetenvir(t_struct_d *data, char *str)
{
  char	**newenv;
  int	a;
  int	b;

  a = 0;
  b = 0;
  my_get_args(data, str);
  if (data->args[0] && data->args[1])
    {
      newenv = my_get_newenv(data, a, b);
      data->tmpenv = my_x_malloc(sizeof(char *) * 150);
      a = 0;
      while (newenv[a])
      	{
      	  data->tmpenv[a] =
	    my_x_malloc(sizeof(char) * my_strlen(newenv[a]) + 2);
      	  my_strcpy(data->tmpenv[a], newenv[a]);
      	  a++;
      	}
      data->tmpenv[a] = NULL;
    }
}
