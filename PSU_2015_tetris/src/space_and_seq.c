/*
** space_and_seq.c for seq space in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Sun Mar 20 16:33:32 2016 Arthur Klein
** Last update Sun Mar 20 19:30:03 2016 Tekm
*/

#include "../include/tetris.h"
#include "../include/my.h"

char            *get_mdf_space(char *tmp, char *str, int cpt_t, int nb)
{
  int           cpt;

  cpt = 0;
  tmp = malloc(sizeof(char) * (my_strlen(str) + (my_strlen("(space)") * nb)));
  while (str && str[cpt])
    {
      if (str[cpt] && str[cpt] == ' ')
	{
	  tmp[cpt_t] = '\0';
	  tmp = my_strcat(tmp, "(space)");
	  cpt_t += my_strlen("(space)") - 1;
	}
      else
	tmp[cpt_t] = str[cpt];
      cpt_t++;
      cpt++;
    }
  tmp[cpt_t] = '\0';
  return (tmp);
}

char            *get_modified_space(char *str)
{
  char          *tmp;
  int           cpt_t;
  int           cpt;
  int           nb;

  nb = 0;
  cpt = 0;
  cpt_t = 0;
  tmp = NULL;
  while (str[cpt])
    {
      if (str[cpt] == ' ')
	nb++;
      cpt++;
    }
  return (get_mdf_space(tmp, str, cpt_t, nb));
}

int             check_sequ(char *str)
{
  int           cpt;

  cpt = 0;
  while (str[cpt])
    {
      if (str[cpt] == 27)
	return (1);
      cpt++;
    }
  return (0);
}

char            *get_mdf_sequ(char *tmp, char *str, int cpt_t, int nb)
{
  int           cpt;

  cpt = 0;
  tmp = malloc(sizeof(char) * (my_strlen(str) + (my_strlen("(space)") * nb)));
  while (str && str[cpt])
    {
      if (str[cpt] && str[cpt] == 27)
	{
	  tmp[cpt_t] = '\0';
	  tmp = my_strcat(tmp, "^E");
	  cpt_t += my_strlen("^E") - 1;
	}
      else
	tmp[cpt_t] = str[cpt];
      cpt_t++;
      cpt++;
    }
  tmp[cpt_t] = '\0';
  return (tmp);
}

char            *get_modified_sequ(char *str)
{
  char          *tmp;
  int           cpt_t;
  int           cpt;
  int           nb;

  nb = 0;
  cpt = 0;
  cpt_t = 0;
  tmp = NULL;
  while (str[cpt])
    {
      if (str[cpt] == 27)
	nb++;
      cpt++;
    }
  return (get_mdf_sequ(tmp, str, cpt_t, nb));
}
