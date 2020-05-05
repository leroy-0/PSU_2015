/*
** my_alias.c for alias in /home/bruere_s/Projet/PSU_2015_42sh/bonus
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Sun Jun  5 17:51:32 2016 bruere_s
** Last update Sun Jun  5 22:54:18 2016 bruere_s
*/

#include	<string.h>
#include	<unistd.h>
#include	"my.h"
#include	"alias.h"
#include	"history.h"
#include	"built_in.h"

void		display_alias(char **alias)
{
  char		**tmp;
  int		i;

  i = 0;
  while (alias[i] != NULL)
    {
      tmp = str_to_wordtab(alias[i], ' ');
      if (strcmp(tmp[0], "alias") == 0)
	{
	  my_putstr(alias[i]);
	  my_putchar('\n');
	}
      free(tmp);
      i++;
    }
}

char		*add_alias_in_str(char *s)
{
  char		*tmp;

  tmp = my_x_malloc(sizeof(char) * (strlen(s) + 7));
  tmp = strcpy(tmp, "alias ");
  tmp = strcat(tmp, s);
  free(s);
  return (tmp);
}

char		**my_alias(char *s, char **env)
{
  char		**cmd;
  char		**alias;
  char		*tmp;

  if (s == NULL)
    {
      if ((alias = gimme_alias()) == NULL)
	return (NULL);
      display_alias(alias);
      free_tab(alias);
      return (env);
    }
  cmd = str_to_wordtab(s, ' ');
  if (check_good_alias(cmd[0], 1) == 0)
    {
      tmp = add_alias_in_str(s);
      add_in_history(tmp, ".42rc");
      free_tab(cmd);
    }
  else
    {
      my_puterr("Error : Bad alias\nUsage : alias NAME=\"COMMAND\"\n");
      return (NULL);
    }
  return (env);
}
