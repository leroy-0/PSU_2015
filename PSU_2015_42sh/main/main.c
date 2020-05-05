/*
** main.c for main in /home/klein_h/Documents/rendu/PSU_2015_42sh/main
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Apr 28 15:43:07 2016 klein_h
** Last update Sun Jun  5 21:17:01 2016 bruere_s
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<signal.h>
#include	<stdio.h>
#include	<string.h>
#include	"get_next_line.h"
#include	"built_in.h"
#include	"exec.h"
#include	"exec_tree.h"
#include	"my.h"
#include	"node.h"

void		handler(int signal)
{
  (void) signal;
  my_putstr("\n$$> ");
}

int		main_loop(char ***myenv)
{
  char		*str;
  t_tree	*tree;
  int		ret;

  ret = 0;
  while ((str = get_next_line(0)) != NULL)
    {
      str = epur_str(str);
      if (str[0] != '\0')
	{
	  tree = parse(str);
	  ret = manage(tree, myenv);
	}
      if (isatty(0) != 0)
	display_prompt(*myenv);
    }
  return (ret);
}

int		main(int ac, char **av, char **env)
{
  char		**myenv;
  int		ret;

  (void)ac;
  (void)av;
  myenv = my_get_env(env);
  signal(SIGINT, handler);
  if (isatty(0) != 0)
    display_prompt(myenv);
  ret = main_loop(&myenv);
  free_tab(myenv);
  if (isatty(0) != 0)
    my_putstr("exit\n");
  return (ret);
}
