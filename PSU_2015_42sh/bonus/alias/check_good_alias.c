/*
** check_good_alias.c for check_good_alias in /home/bruere_s/Projet/PSU_2015_42sh/bonus
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Sun Jun  5 22:56:16 2016 bruere_s
** Last update Sun Jun  5 22:57:13 2016 bruere_s
*/

#include	"my.h"

int		check_good_alias(char *s, int mode)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  while (s[i] != '\0')
    {
      if (s[i] == '=')
	{
	  if (s[i + 1] == '\0' || s[i + 1] == ' ' || s[i + 1] == '\t')
	    return (1);
	}
      if (s[i] == ' ' && mode == 1)
	return (1);
      if (s[i] == '=')
	nb++;
      i++;
    }
  if (nb != 1)
    return (1);
  return (0);
}
