/*
** main.c for main in /home/klein_h/Documents/rendu/PSU_2015_42sh/main
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Apr 28 15:43:07 2016 klein_h
** Last update Sun Jun  5 21:33:58 2016 leroy_0
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<signal.h>
#include	<stdio.h>
#include	<string.h>
#include	<glob.h>
#include	"get_next_line.h"
#include	"exec_tree.h"
#include	"built_in.h"
#include	"bonus.h"
#include	"history.h"
#include	"exec.h"
#include	"node.h"
#include	"my.h"
#include	"alias.h"

char		**myenv;

void		handler(int signal)
{
  (void) signal;
  putchar('\n');
  display_prompt(myenv);
}

char		*check_variable(char *str, char **myenv)
{
  char		**alias;

  if ((alias = gimme_alias()) != NULL)
    if ((str = change_variable_alias(alias, str)) == NULL)
      return (NULL);
  if ((str = change_variable_history(str)) == NULL)
    return (NULL);
  else if ((str = change_local_variables_str(str, myenv)) == NULL)
    return (NULL);
  else if ((str = check_globing(str)) == NULL)
    return (NULL);
  return (str);
}

char		*make_history(char *str, char **myenv)
{
  int		fd;

  if (init_term(1, myenv) == 1)
    return (NULL);
  fd = open_file_sh(1, ".42_history");
  if (fd != -1)
    close(fd);
  return (str);
}

int		main_loop(char ***myenv, int ret)
{
  t_tree	*tree;
  char		*str;

  while ((str = my_getstr(*myenv)) != NULL)
    {
      str = epur_str(str);
      if ((str = make_history(str, *myenv)) == NULL)
	return (1);
      if (str[0] != '\0')
	{
	  if (str[0] != '!')
	    add_in_history(str, ".42_history");
	  if ((str = check_variable(str, *myenv)) != NULL)
	    {
	      tree = parse(str);
	      ret = manage(tree, myenv);
	      move_hist('c', *myenv);
	    }
	}
      if (isatty(0) != 0)
	display_prompt(*myenv);
      if (init_term(0, *myenv) == 1)
      	return (1);
    }
  return (ret);
}

int		main(int ac, char **av, char **env)
{
  int		ret;

  (void)ac;
  (void)av;
  ret = 0;
  myenv = my_get_env(env);
  if (init_term(0, myenv) == 1)
    return (1);
  signal(SIGINT, handler);
  put_my_ascii();
  if (isatty(0) != 0)
    display_prompt(myenv);
  ret = main_loop(&myenv, ret);
  if (init_term(1, myenv) == 1)
    return (1);
  free_tab(myenv);
  if (isatty(0) != 0)
    my_putstr("exit\n");
  return (ret);
}
