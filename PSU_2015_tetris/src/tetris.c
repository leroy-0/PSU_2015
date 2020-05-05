/*
** my_select.c for my_select in /home/leroy_0/rendu/PSU_2015_my_select
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Mon Nov 30 13:20:58 2015 leroy_0
** Last update Sun Mar 20 19:30:34 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"
#include "../include/get_next_line.h"

t_struct_d		*init_values()
{
  t_struct_d	*data;

  data = malloc(sizeof(*data));
  data->down_k = 0;
  data->pause_k = 0;
  data->level = 1;
  data->highscore = 0;
  data->score = 0;
  data->min = 0;
  data->left = get_that_key("kcub1");
  data->right = get_that_key("kcuf1");
  data->turn = get_that_key("kcuu1");
  data->drop = get_that_key("kcud1");
  data->quit = "q";
  data->pause = "(space)";
  data->next = "Yes";
  data->sizes.x = 10;
  data->sizes.y = 20;
  return (data);
}

int             keypress()
{
  static struct termios oldt;
  static struct termios newt;
  int           c;

  ioctl(0, TCGETS, &oldt);
  ioctl(0, TCGETS, &newt);
  newt.c_lflag &= ~ECHO;
  newt.c_lflag &= ~ICANON;
  ioctl(0, TCSETS, &newt);
  c = read(0, &c, 1);
  ioctl(0, TCSETS, &oldt);
  return (c);
}

int 		opt_level(t_struct_d *data, char **av, t_ctrl *ctrl)
{
  if (ctrl->t == 1)
    {
      ctrl->j++;
      if (!av[ctrl->j])
	{
	  my_putstr("Error syntax : Invalid option \n");
	  return (1);
	}
      if (check_int(av[ctrl->j]) == 0)
	data->level = my_strint(av[ctrl->j]);

    }
  else
    {
      if (check_level(av[ctrl->j]) == 0)
	data->level = my_strint(get_equal(av[ctrl->j]));
    }
  return (0);
}

void		do_tetris(int ac, char **av)
{
  t_struct_d	*data;
  t_ptr_fnct	*tabs;

  data = init_values();
  tabs = init_data();
  if (ac > 1)
    {
      if (manage_my_arg(av, tabs, ac, data) == 1)
	return;
    }
  if (tetris(data) == 1)
    my_putstr("Error : The windows is too small !!!\n");
  free(data);
}

int		main(int ac, char **av, char **env)
{
  if (env == NULL || env[0] == NULL)
    {
      my_putstr("Error: Cannot open\n");
      return (1);
    }
  do_tetris(ac, av);
  return (0);
}
