/*
** globing.c for globing in /home/bruere_s/Projet/PSU_2015_42sh/bonus
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Sat Jun  4 23:01:02 2016 bruere_s
** Last update Sat Jun  4 23:02:59 2016 bruere_s
*/

#include	<glob.h>
#include	<unistd.h>
#include	"my.h"

int		check_star(char *s)
{
  int		i;

  i = 0;
  while (s[i] != '\0')
    {
      if (s[i] == '*')
	return (i);
      i++;
    }
  return (-1);
}

char		*switch_to_globing(char *s, char *tmp)
{
  glob_t	check;
  char		*str;

  if (glob(tmp, 0, NULL, &check) < 0)
    return (s);
  if ((str = tab_to_str(check.gl_pathv)) == NULL)
    return (s);
  return (str);
}

char		*check_globing(char *s)
{
  char		**tmp;
  int		i;

  i = 0;
  tmp = str_to_wordtab(s, ' ');
  while (tmp[i] != NULL)
    {
      if (check_star(tmp[i]) != -1)
	{
	  tmp[i] = switch_to_globing(s, tmp[i]);
	  s = tab_to_str(tmp);
	  return (s);
	}
      i++;
    }
  return (s);
}
