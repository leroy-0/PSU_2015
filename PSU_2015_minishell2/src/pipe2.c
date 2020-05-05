/*
** pipe2.c for pipe2 in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 10:05:39 2016 leroy_0
** Last update Thu Apr 21 10:05:47 2016 leroy_0
*/

#include "my.h"
#include "mysh.h"
#include "struct.h"

int		check_pipe(char *str)
{
  int		nbpipe = 0;
  int		cpt = 0;

  while (str && str[cpt])
    {
      if (str[cpt] == '|')
	nbpipe++;
      cpt++;
    }
  return (nbpipe);
}

void		init_that(t_pipe *piper, char *str)
{
  if ((piper->cpt_c - 1) >= 0 && str[piper->cpt - 1] == ' ')
    piper->args[piper->cpt_a][piper->cpt_c - 1] = '\0';
  else
    piper->args[piper->cpt_a][piper->cpt_c] = '\0';
  piper->cpt_a++;
  if (str[piper->cpt + 2] == ' ')
    piper->cpt += 3;
  else
    piper->cpt += 2;
  piper->cpt_c = 0;
  piper->args[piper->cpt_a] = my_x_malloc(sizeof(char) * my_strlen(str) + 1);
}

void		init_this(t_pipe *piper, char *str)
{
  if ((piper->cpt_c - 1) >= 0 && str[piper->cpt - 1] == ' ')
    piper->args[piper->cpt_a][piper->cpt_c - 1] = '\0';
  else
    piper->args[piper->cpt_a][piper->cpt_c] = '\0';
  piper->cpt_a++;
  if (str[piper->cpt + 1] == ' ')
    piper->cpt += 2;
  else
    piper->cpt++;
  piper->cpt_c = 0;
  piper->args[piper->cpt_a] = my_x_malloc(sizeof(char) * my_strlen(str) + 1);
}

char		**get_cut_args(t_pipe *piper, char *str, int nbargs, char ch)
{
  piper->cpt = 0;
  piper->cpt_c = 0;
  piper->cpt_a = 0;
  piper->args = my_x_malloc(sizeof(char *) * (nbargs + 1));
  piper->args[piper->cpt_a] = my_x_malloc(sizeof(char) * my_strlen(str) + 1);
  while (str[piper->cpt])
    {
      piper->args[piper->cpt_a][piper->cpt_c] = str[piper->cpt];
      if (str[piper->cpt] == ch && str[piper->cpt + 1] == ch)
	init_that(piper, str);
      else if (str[piper->cpt] == ch)
	init_this(piper, str);
      else
	{
	  piper->cpt++;
	  piper->cpt_c++;
	}
    }
  if (str[piper->cpt - 1] == '\n')
    piper->args[piper->cpt_a][piper->cpt_c - 1] = '\0';
  else
    piper->args[piper->cpt_a][piper->cpt_c] = '\0';
  piper->args[piper->cpt_a + 1] = NULL;
  return (piper->args);
}

int		check_redir(char *str)
{
  int		cpt;

  cpt = 0;
  while (str && str[cpt])
    {
      if (str[cpt] == '>' && str[cpt + 1] != '>')
	return (1);
      else if (str[cpt] == '<' && str[cpt + 1] != '<')
	return (2);
      else if (str[cpt] == '>' && str[cpt + 1] == '>')
	return (3);
      else if (str[cpt] == '<' && str[cpt + 1] == '<')
	return (4);
      cpt++;
    }
  return (0);
}
