/*
** my_ptr_fnct3.c for my_ptr_fnct3 in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Sun Mar 20 16:36:36 2016 Arthur Klein
** Last update Sun Mar 20 19:27:47 2016 Tekm
*/

#include "../include/tetris.h"
#include "../include/my.h"

int 		key_left_long(char **av, t_ctrl *ctrl, t_struct_d *data)
{
  if (check_equal(av[ctrl->j]) == 0)
    {
      if (check_space(get_equal(av[ctrl->j])) == 1)
	data->left = get_modified_space(get_equal(av[ctrl->j]));
      else
	data->left = get_equal(av[ctrl->j]);
      if (check_sequ(data->left) == 1)
	data->left = get_modified_sequ(data->left);
      return (0);
    }
  return (1);
}

char            *get_that_key(char *str)
{
  char		*str_key;
  int		j;

  if (setupterm(NULL, 1, &j) == ERR)
    {
      endwin();
      delwin(stdscr);
      exit(1);
    }
  if (j != 1)
    {
      endwin();
      delwin(stdscr);
      exit(1);
    }
  str_key = tigetstr(str);
  if (str_key == NULL)
    {
      endwin();
      delwin(stdscr);
      exit(1);
    }
  return (str_key);
}
