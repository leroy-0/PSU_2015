/*
** change_local_variable.c for exec in /home/bruere_s/Projet/PSU_2015_42sh/exec
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Thu Jun  2 22:02:22 2016 bruere_s
** Last update Sun Jun  5 23:39:11 2016 longle_h
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"my.h"
#include	"built_in.h"
#include	"history.h"

static t_echo_special	*init_tab_special()
{
  t_echo_special	*tab;

  if ((tab = my_x_malloc(sizeof(t_echo_special) * 8)) == NULL)
    return (NULL);
  tab[0].car = '0';
  tab[0].func_special = &(echo_O_special);
  tab[1].car = 'n';
  tab[1].func_special = &(echo_n_special);
  tab[2].car = '#';
  tab[2].func_special = &(echo_sharp_special);
  tab[3].car = '*';
  tab[3].func_special = &(echo_star_special);
  tab[4].car = '@';
  tab[4].func_special = &(echo_at_special);
  tab[5].car = '?';
  tab[5].func_special = &(echo_inte_special);
  tab[6].car = '$';
  tab[6].func_special = &(echo_dollard_special);
  tab[7].car = '!';
  tab[7].func_special = &(echo_excla_special);
  return (tab);
}

char			*find_special_variables(char *s)
{
  t_echo_special	*tab;
  int			check;
  int			i;

  i = 0;
  check = 0;
  if (strlen(s) == 1)
    {
      if ((tab = init_tab_special()) == NULL)
	return (NULL);
      while (i < 8)
	{
	  if (s[0] == tab[i].car)
	    {
	      check = 1;
	      s = (tab[i].func_special)(s);
	    }
	  i++;
	}
      if (check == 0)
	return (NULL);
      free(tab);
    }
  return (s);
}

char		*special_case(char *tab)
{
  char		*tmp;

  tmp = strdup(tab);
  if ((tab = find_special_variables(tab)) == NULL)
    {
      my_puterr(tmp);
      my_puterr(": Undefined variable.\n");
      free(tmp);
      return (NULL);
    }
  else
    return (tab);
}

char		**change_local_variables(char **av, char **env)
{
  int		i;
  char		*tmp;

  i = 0;
  while (av[i] != NULL)
    {
      if (strlen(av[i]) != 1 && av[i][0] == '$')
	{
	  av[i] = my_str_cut(av[i], 1);
	  if (strlen(av[i]) == 1)
	    av[i] = special_case(av[i]);
	  else
	    {
	      if ((tmp = my_search_env(av[i], env)) != NULL)
		av[i] = strdup(tmp);
	      else
		return (display_error_local_variable_tab(av[i]));
	    }
	}
      i++;
    }
  return (av);
}

char		*change_local_variables_str(char *str, char **env)
{
  char		**tab;
  char		*tmp;
  int		i;

  i = 0;
  tab = str_to_wordtab(str, ' ');
  while (tab[i] != NULL)
    {
      if (strlen(tab[i]) != 1 && tab[i][0] == '$')
	{
	  tab[i] = my_str_cut(tab[i], 1);
	  if (strlen(tab[i]) == 1)
	    tab[i] = special_case(tab[i]);
	  else
	    {
	      if ((tmp = my_search_env(tab[i], env)) != NULL)
		tab[i] = strdup(tmp);
	      else
		return (display_error_local_variable(tab[i]));
	    }
	}
      i++;
    }
  tmp = tab_to_str(tab);
  return (tmp);
}
