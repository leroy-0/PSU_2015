/*
** my_ptr_fnct2.c for ptr_function2 in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Sun Mar 20 16:19:15 2016 Arthur Klein
** Last update Sun Mar 20 19:27:37 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"

int 		key_drop_long(char **av, t_ctrl *ctrl, t_struct_d *data)
{
  if (check_equal(av[ctrl->j]) == 0)
    {
      if (av[ctrl->j] && check_space(get_equal(av[ctrl->j])) == 1)
	data->drop = get_modified_space(get_equal(av[ctrl->j]));
      else if (av[ctrl->j])
	data->drop = get_equal(av[ctrl->j]);
      if (check_sequ(data->drop) == 1)
	data->drop = get_modified_sequ(data->drop);
    }
  else
    {
      my_putstr("Error: bad argument\n");
      return (1);
    }
  return (0);
}

int 		key_pause_long(char **av, t_ctrl *ctrl, t_struct_d *data)
{
  if (check_equal(av[ctrl->j]) == 0)
    {
      if (av[ctrl->j] && check_space(get_equal(av[ctrl->j])) == 1)
	data->pause = get_modified_space(get_equal(av[ctrl->j]));
      else if (av[ctrl->j])
	data->pause = get_equal(av[ctrl->j]);
      if (check_sequ(data->pause) == 1)
	data->pause = get_modified_sequ(data->pause);
    }
  else
    {
      my_putstr("Error: bad argument\n");
      return (1);
    }
  return (0);
}

int 		key_turn_long(char **av, t_ctrl *ctrl, t_struct_d *data)
{
  if (check_equal(av[ctrl->j]) == 0)
    {
      if (check_space(get_equal(av[ctrl->j])) == 1)
	data->turn = get_modified_space(get_equal(av[ctrl->j]));
      else
	data->turn = get_equal(av[ctrl->j]);
      if (check_sequ(data->turn) == 1)
	data->turn = get_modified_sequ(data->turn);
      return (0);
    }
  return (1);
}

int 		key_right_long(char **av, t_ctrl *ctrl, t_struct_d *data)
{
  if (check_equal(av[ctrl->j]) == 0)
    {
      if (check_space(get_equal(av[ctrl->j])) == 1)
	data->right = get_modified_space(get_equal(av[ctrl->j]));
      else
	data->right = get_equal(av[ctrl->j]);
      if (check_sequ(data->right) == 1)
	data->right = get_modified_sequ(data->right);
      return (0);
    }
  return (1);
}
int 		key_quit_long(char **av, t_ctrl *ctrl, t_struct_d *data)
{
  if (check_equal(av[ctrl->j]) == 0)
    {
      if (check_space(get_equal(av[ctrl->j])) == 1)
	data->quit = get_modified_space(get_equal(av[ctrl->j]));
      else
	data->quit = get_equal(av[ctrl->j]);
      if (check_sequ(data->quit) == 1)
	data->quit = get_modified_sequ(data->quit);
      return (0);
    }
  return (1);
}
