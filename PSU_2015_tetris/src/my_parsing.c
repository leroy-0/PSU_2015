/*
** my_parsing.c for parsing in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Mar 17 10:46:26 2016 Arthur Klein
** Last update Thu Mar 17 21:39:09 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"

t_ptr_fnct	*init_suite(t_ptr_fnct *tabs)
{
  tabs[7].opt[0] = "--key-pause";
  tabs[7].ptr = &opt_keypause;
  tabs[7].opt[1] = "-kp";
  tabs[8].opt[0] = "--map-size";
  tabs[8].ptr = &opt_mapsize;
  tabs[8].opt[1] = "ms";
  tabs[9].opt[0] = "--without-next";
  tabs[9].ptr = &opt_without_next;
  tabs[9].opt[1] = "-w";
  tabs[10].opt[0] = "--debug";
  tabs[10].ptr = &debug_mode;
  tabs[10].opt[1] = "-d";
  tabs[11].opt[0] = NULL;
  return (tabs);
}

t_ptr_fnct	*init_data()
{
  t_ptr_fnct 	*tabs;

  tabs = malloc(sizeof(t_ptr_fnct) * 12);
  tabs[0].ptr = &opt_help;
  tabs[0].opt[0] = "--help";
  tabs[0].opt[1] = "-h";
  tabs[1].opt[0] = "--level=";
  tabs[1].ptr = &opt_level;
  tabs[1].opt[1] = "-l";
  tabs[2].opt[0] = "--key-left=";
  tabs[2].ptr = &opt_keyleft;
  tabs[2].opt[1] = "-kl";
  tabs[3].opt[0] = "--key-right=";
  tabs[3].ptr = &opt_keyright;
  tabs[3].opt[1] = "-kr";
  tabs[4].opt[0] = "--key-turn=";
  tabs[4].ptr = &opt_keyturn;
  tabs[4].opt[1] = "-kt";
  tabs[5].opt[0]= "--key-drop=";
  tabs[5].ptr = &opt_keydrop;
  tabs[5].opt[1] = "-kd";
  tabs[6].opt[0] = "--key-quit=";
  tabs[6].ptr = &opt_keyquit;
  tabs[6].opt[1] = "-kq";
  return (init_suite(tabs));
}

int 		my_pars(t_ctrl *ctrl, t_ptr_fnct *tabs,
t_struct_d *data, char **av)
  {
    char 		*len;

    while (ctrl->t < 2)
      {
	if ((my_strlen(tabs[ctrl->i].opt[ctrl->t]) > 1
	&& my_strlen(tabs[ctrl->i].opt[ctrl->t]) < 4)
	|| my_strlen(tabs[ctrl->i].opt[ctrl->t]) == 7)
	len = av[ctrl->j];
	else
	  len = tabs[ctrl->i].opt[ctrl->t];

	if (my_strncmp(tabs[ctrl->i].opt[ctrl->t],
	av[ctrl->j], my_strlen(len)) == 0)
	  {
	    if ((tabs[ctrl->i].ptr)(data, av, ctrl) == 1)
	      return (1);
	    ctrl->where = 1;
	  }
	ctrl->t++;
      }
    return (0);
  }

int		do_pars(t_ctrl *ctrl, char **av, t_ptr_fnct *tabs, t_struct_d *data)
{
  while (ctrl->j < ctrl->ac &&  tabs[ctrl->i].opt[0] != NULL)
    {
      if (my_pars(ctrl, tabs, data, av) == 1)
	return (1);
      ctrl->t = 0;
      ctrl->i++;
      if (tabs[ctrl->i].opt[0] == NULL)
	{
	  if (ctrl->where == 0)
	    {
	      my_putstr("Error syntax : Invalid option \n");
	      return (1);
	    }
	  ctrl->where = 0;
	  ctrl->j++;
	  ctrl->i = 0;
	}
    }
  return (0);
}

int		manage_my_arg(char **av, t_ptr_fnct *tabs, int ac, t_struct_d *data)
{
  t_ctrl 	ctrl;

  ctrl.j = 1;
  ctrl.i = 0;
  ctrl.t = 0;
  ctrl.where = 0;
  ctrl.aff = 0;
  ctrl.ac = ac;
  if (do_pars(&ctrl, av, tabs, data) == 1)
    return (1);
  if (ctrl.aff == 1)
    {
      show_debug(data);
      keypress(0);
    }
  return (0);
}
