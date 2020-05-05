/*
** my_opt_key.c for opt_key in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Mar 17 10:38:01 2016 Arthur Klein
** Last update Sun Mar 20 04:55:44 2016 Tekm
*/
#include "../include/tetris.h"
#include "../include/my.h"

int             check_space(char *str)
{
  int           cpt;

  cpt = 0;
  while (str[cpt])
    {
      if (str[cpt] == ' ')
	return (1);
      cpt++;
    }
  return (0);
}

int             opt_keyleft(t_struct_d *data, char **av, t_ctrl *ctrl)
{
  if (ctrl->t == 1)
    {
      ctrl->j++;
      if (!av[ctrl->j])
	{
	  return (0);
	}
      if (check_space(av[ctrl->j]) == 1)
	data->left = get_modified_space(av[ctrl->j]);
      else
	data->left = av[ctrl->j];
      if (check_sequ(data->left) == 1)
	data->left = get_modified_sequ(data->left);
      return (0);
    }
  else
    {
      if (key_left_long(av, ctrl, data) == 0)
	return (0);
    }
  my_putstr("Error: bad argument\n");
  return (1);
}

int 		opt_keyquit(t_struct_d *data, char **av, t_ctrl *ctrl)
{
  if (ctrl->t == 1)
    {
      ctrl->j++;
      if (!av[ctrl->j])
	{
	  return (0);
	}
      if (check_space(av[ctrl->j]) == 1)
	data->quit = get_modified_space(av[ctrl->j]);
      else
	data->quit = av[ctrl->j];
      if (check_sequ(data->quit) == 1)
	data->quit = get_modified_sequ(data->quit);
      return (0);
    }
  else
    {
      if (key_quit_long(av, ctrl, data) == 0)
	return (0);
    }
  my_putstr("Error: bad argument\n");
  return (1);
}

int 		opt_keyright(t_struct_d *data, char **av, t_ctrl *ctrl)
{
  if (ctrl->t == 1)
    {
      ctrl->j++;
      if (!av[ctrl->j])
	{
	  return (0);
	}
      if (check_space(av[ctrl->j]) == 1)
	data->right = get_modified_space(av[ctrl->j]);
      else
	data->right = av[ctrl->j];
      if (check_sequ(data->right) == 1)
	data->right = get_modified_sequ(data->right);
      return (0);
    }
  else
    {
      if (key_right_long(av, ctrl, data) == 0)
	return (0);
    }
  my_putstr("Error: bad argument\n");
  return (1);
}

int 		opt_keyturn(t_struct_d *data, char **av, t_ctrl *ctrl)
{
  if (ctrl->t == 1)
    {
      ctrl->j++;
      if (!av[ctrl->j])
	{
	  return (0);
	}
      if (check_space(av[ctrl->j]) == 1)
	data->turn = get_modified_space(av[ctrl->j]);
      else
	data->turn = av[ctrl->j];
      if (check_sequ(data->turn) == 1)
	data->turn = get_modified_sequ(data->turn);
      return (0);
    }
  else
    {
      if (key_turn_long(av, ctrl, data) == 0)
	return (0);
    }
  my_putstr("Error: bad argument\n");
  return (1);
}
