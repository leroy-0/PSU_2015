/*
** pipe4.c for pipe4 in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:06:32 2016 leroy_0
** Last update Thu Apr 21 10:06:41 2016 leroy_0
*/

#include "my.h"
#include "mysh.h"
#include "struct.h"

int             my_whil_p(t_pipe *data, int a, int b, char *str)
{
  while (str && str[a] != ' ' && str[a] != '\0')
    {
      data->args[data->nbarg][b] = str[a];
      a++;
      b++;
    }
  data->args[data->nbarg][b] = '\0';
  return (a);
}

char		**my_get_args_p(char *str)
{
  t_pipe		data;
  int                   a;
  int                   b;

  a = 0;
  b = 0;
  data.nbarg = 0;
  data.args = my_x_malloc(sizeof(char *) * (my_strlen(str) + 1));
  while (str && str[a] != '\0')
    {
      data.args[data.nbarg] = my_x_malloc(sizeof(char) * (my_strlen(str) + 1));
      a = my_whil_p(&data, a, b, str);
      data.nbarg++;
      b = 0;
      if (str[a] != '\0')
        a++;
    }
  data.args[data.nbarg] = NULL;
  return (data.args);
}
