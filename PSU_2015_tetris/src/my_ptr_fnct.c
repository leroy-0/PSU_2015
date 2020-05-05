/*
** my_ptr_fnct.c for my_ptr_fnct in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Wed Mar 16 18:34:13 2016 Arthur Klein
** Last update Sun Mar 20 04:57:09 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"

int 		opt_keydrop(t_struct_d *data, char **av, t_ctrl *ctrl)
{
  if (ctrl->t == 1)
    {
      ctrl->j++;
      if (av[ctrl->j] && check_space(av[ctrl->j]) == 1)
	data->drop = get_modified_space(av[ctrl->j]);
      else if (av[ctrl->j])
	data->drop = av[ctrl->j];
      else if (av[ctrl->j] == NULL)
	{
	  my_putstr("Syntax error : Invalid argument\n");
	  return (1);
	}
      if (check_sequ(data->drop) == 1)
	data->drop = get_modified_sequ(data->drop);
      return (0);
    }
  else
    {
      if (key_drop_long(av, ctrl, data) == 1)
	return (1);
    }
  return (0);
}

int 		opt_keypause(t_struct_d *data, char **av, t_ctrl *ctrl)
{
  if (ctrl->t == 1)
    {
      ctrl->j++;
      if (av[ctrl->j] && check_space(av[ctrl->j]) == 1)
	data->pause = get_modified_space(av[ctrl->j]);
      else if (av[ctrl->j])
	data->pause = av[ctrl->j];
      else if (av[ctrl->j] == NULL)
	{
	  my_putstr("Syntax error : Invalid argument\n");
	  return (1);
	}
      if (check_sequ(data->pause) == 1)
	data->pause = get_modified_sequ(data->pause);
      return (0);
    }
  else
    {
      if (key_pause_long(av, ctrl, data) == 1)
	return (1);
    }
  return (0);
}

int 		opt_mapsize(t_struct_d *data, char **av, t_ctrl *ctrl)
{
  if (check_str(av[ctrl->j]) == 0)
    {
      data->sizes.x = get_sizes(av[ctrl->j], 2);
      data->sizes.y = get_sizes(av[ctrl->j], 1);
    }
  else
    {
      my_putstr("Error: bad argument\n");
      return (1);
    }
  return (0);
}

int 		debug_mode(t_struct_d *data, char **av, t_ctrl *ctrl)
{
  (void)ctrl;
  (void)(av);
  (void)data;
  ctrl->aff = 1;
  return (0);
}

int 		opt_without_next(t_struct_d *data, char **av, t_ctrl *ctrl)
{
  (void)ctrl;
  (void)(av);
  data->next = "No";
  return (0);
}
