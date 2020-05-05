/*
** tab_to_str.c for tab_to_str in /home/bruere_s/Projet/PSU_2015_42sh
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Thu Jun  2 20:54:03 2016 bruere_s
** Last update Sun Jun  5 20:27:14 2016 bruere_s
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"../../include/my.h"

static int	my_tab_len(char **tab, int *len)
{
  int		i;

  i = 0;
  *len = 0;
  while (tab[i] != NULL)
    {
      (*len) += my_strlen(tab[i]);
      i++;
    }
  return (i);
}

char		*tab_to_str(char **tab)
{
  int		i;
  int		len;
  int		word;
  char		*s;

  i = 0;
  word = my_tab_len(tab, &len);
  s = my_x_malloc(sizeof(char) * (len + word + 1));
  word = 0;
  while (tab[i] != NULL)
    {
      len = 0;
      while (tab[i][len] != '\0')
	{
	  s[word] = tab[i][len];
	  len++;
	  word++;
	}
      if (tab[i + 1] != NULL)
	s[word++] = ' ';
      i++;
    }
  s[word] = '\0';
  return (s);
}
