/*
** prompt.c for prompt in /home/bruere_s/Projet/PSU_2015_42sh
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Sun Jun  5 21:13:32 2016 bruere_s
** Last update Sun Jun  5 21:14:58 2016 bruere_s
*/

#include	<unistd.h>
#include	"built_in.h"
#include	"my.h"

void		display_pwd(char *tmp, char **env)
{
  tmp = my_search_env("PWD", env);
  if (tmp)
    {
      my_putstr(tmp);
      free(tmp);
    }
}

void		display_prompt(char **env)
{
  char		*tmp;

  tmp = my_search_env("USER", env);
  if (tmp)
    {
      my_putstr(tmp);
      free(tmp);
      if ((tmp = my_search_env("PWD", env)) != NULL)
	{
	  my_putchar(':');
	  free(tmp);
	}
    }
  display_pwd(tmp, env);
  my_putstr("> ");
}
