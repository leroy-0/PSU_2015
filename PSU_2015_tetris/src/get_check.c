/*
** get_check.c for get_check in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Mar 17 13:24:49 2016 Arthur Klein
** Last update Sun Mar 20 19:25:32 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"

int                     check_whl_args(t_check *check, int disp)
{
  while (check->str[check->cpt])
    {
      if (check->str[check->cpt] != ' ')
        {
          if (check->arg == 0)
            {
              if (check_args0(check, disp) == 1)
                return (1);
            }
          else if (check->arg == 1)
            {
              if (check_args1(check, disp) == 1)
                return (1);
            }
          else if (check->arg == 2)
            {
              if (check_args2(check, disp) == 1)
                break;
            }
        }
      check->cpt++;
    }
  return (0);
}

int		get_sizes(char *str, int nb)
{
  int		cpt;

  cpt = 0;
  while (str[cpt] && str[cpt] != '=')
    cpt++;
  cpt++;
  if (nb == 1)
    return (get_y(str, cpt, nb));
  else if (nb == 2)
    return (get_x(str, cpt, nb));
  return (0);
}

int		check_int(char *str)
{
  int		cpt;

  cpt = 0;
  if (str[cpt] == '\0' || str[cpt] == '0')
    return (1);
  while (str[cpt])
    {
      if (str[cpt] < '0' || str[cpt] > '9')
	return (1);
      cpt++;
    }
  return (0);
}

int		check_equal(char *str)
{
  int		cpt;

  cpt = 0;
  while (str[cpt] && str[cpt] != '=')
    cpt++;
  if (str[cpt] == '=')
    {
      cpt++;
      if (str[cpt] == '\0')
	return (1);
      if (str[cpt])
	cpt++;
      return (0);
    }
  return (1);
}

char		*get_equal(char *str)
{
  char		*res_r;
  char		res[50];
  int		cpt_r;
  int		cpt;

  cpt = 0;
  cpt_r = 0;
  while (str[cpt] && str[cpt] != '=')
    cpt++;
  if (str[cpt] == '=')
    {
      cpt++;
      while (str[cpt])
	{
	  res[cpt_r] = str[cpt];
	  cpt_r++;
	  cpt++;
	}
      res[cpt_r] = '\0';
      res_r = malloc(sizeof(char) * my_strlen(res) + 1);
      res_r = my_strcpy(res_r, res);
      return (res_r);
    }
  return (NULL);
}
