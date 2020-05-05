/*
** change_variable_history.c for history in /home/bruere_s/Projet/PSU_2015_42sh/bonus/exec
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Sat Jun  4 18:05:51 2016 bruere_s
** Last update Sun Jun  5 18:11:38 2016 leroy_0
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	"history.h"
#include	"my.h"

static char	*display_error_change_history(char *tmp)
{
  write(2, tmp, strlen(tmp));
  write(2, ": Event not found.\n", 20);
  return (NULL);
}

static char	*change_history_for_numbers(char *s, char *tmp, char **hist)
{
  int		nb;
  int		i;

  if ((nb = my_getnbr(tmp)) < 0)
    i = my_tablen(hist) - 1;
  else
    i = 0;
  if (nb < 0)
    {
      if ((nb * -1) > i || (nb * -1) < 1)
	return (display_error_change_history(tmp));
      else
	if (hist[i - ((nb + 1) * -1)])
	  s = strdup(hist[i - ((nb + 1) * -1)]);
    }
  else
    {
      if (nb > my_tablen(hist) || nb < 1)
	return (display_error_change_history(tmp));
      else
	if (hist[nb - 1])
	  s = strdup(hist[nb - 1]);
    }
  return (s);
}

static char	*change_history_for_letters(char *s, char *tmp, char **hist)
{
  int		i;

  i = my_tablen(hist) - 1;
  while (i >= 0)
    {
      if (my_strncmp(tmp, hist[i], strlen(tmp)) == 0)
	return (s = strdup(hist[i]));
      i--;
    }
  write(2, tmp, strlen(tmp));
  write(2, ": Event not found.\n", 20);
  return (NULL);
}

static char	*hub_change(char *tmp, char *tab, char *s, char **hist)
{
  if (strlen(tmp) > 0 && tmp[0] == '!' && tmp[1] != '!')
    {
      if (hist[my_tablen(hist) - 1])
	tab = hist[my_tablen(hist) - 1];
    }
  else if (tmp[0] == '-' || (tmp[0] >= '0' && tmp[0] <= '9'))
    {
      if ((tab = change_history_for_numbers(s, tmp, hist)) == NULL)
	return (NULL);
    }
  else if ((tmp[0] >= 'A' && tmp[0] <= 'Z')
	   || (tmp[0] >= 'a' && tmp[0] <= 'z'))
    if ((tab = change_history_for_letters(s, tmp, hist)) == NULL)
      return (NULL);
  add_in_history(tab, ".42_history");
  my_putstr(tab);
  my_putchar('\n');
  return (tab);
}

char		*change_variable_history(char *s)
{
  char		**tab;
  char		*tmp;
  char		**hist;
  int		i;

  i = 0;
  tab = str_to_wordtab(s, ' ');
  while (tab[i] != NULL)
    {
      if (strlen(tab[i]) > 1 && tab[i][0] == '!')
	{
	  tmp = my_str_cut(s, 1);
	  if ((hist = gimme_hist()) == NULL)
	    return (s);
	  if (strlen(tmp) > 0)
	    if ((tab[i] = hub_change(tmp, tab[i], s, hist)) == NULL)
	      return (NULL);
	}
      i++;
    }
  s = tab_to_str(tab);
  return (s);
}
