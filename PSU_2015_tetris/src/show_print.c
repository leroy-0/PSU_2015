/*
** show_print.c for show_print in /home/klein_h/Documents/PSU_2015_tetris/src
**
** Made by Arthur Klein
** Login   <klein_h@epitech.net>
**
** Started on  Thu Mar 17 11:01:22 2016 Arthur Klein
** Last update Sun Mar 20 19:29:24 2016 Tekm
*/
#include "../include/my.h"
#include "../include/tetris.h"

void 		print_my_error(char *name)
{
  my_putstr("Usage: ");
  my_putstr(name);
  my_putstr(" [options]\n");
  my_putstr("Options:\n");
  my_putstr("  --help		Display this help\n");
  my_putstr("  -l --level={num}	Start Tetris at level num\n");
  my_putstr("  -kl --key-left={K}	Move tetrimino on LEFT with key K\n");
  my_putstr("  -kr --key-right={K}	Move tetrimino on RIGHT with key K\n");
  my_putstr("  -kt --key-turn={K}	Turn tetrimino with key K\n");
  my_putstr("  -kd --key-drop={K}	Set default DROP on key K\n");
  my_putstr("  -kq --key-quit={K}	Quit program when press key K\n");
  my_putstr(
  "  -kp --key-pause={K}	Pause and restart game when press key K\n");
  my_putstr("  --map-size={row,col}	Set game size at row, col\n");
  my_putstr("  -w --without-next	Hide next tetrimino\n");
  my_putstr("  -d --debug		Debug mode\n");
}

void 		show_debugs_s(t_struct_d *data)
{
  my_put_nbr(data->sizes.x);
  my_putchar('\n');
  if (opendir("tetriminos/") == NULL)
    {
      my_putstr(
	"Error: we could launch tetris due to missing directory 'tetriminos'\n");
      exit(1);
    }
  check_files("tetriminos/", 0);
  my_putstr("Press a key to start Tetris\n");
}

void		show_debugs(t_struct_d *data)
{
  if (my_strcmp(data->drop, get_that_key("kcud1")) == 0)
    {
      my_putstr("Key Drop : ^");
      data->drop[0] = 'E';
    }
  else
    my_putstr("Key Drop : ");
  my_putstr(data->drop);
  my_putchar('\n');
  my_putstr("Key Quit : ");
  my_putstr(data->quit);
  my_putchar('\n');
  my_putstr("Key Pause : ");
  my_putstr(data->pause);
  my_putchar('\n');
  my_putstr("Next : ");
  my_putstr(data->next);
  my_putchar('\n');
  my_putstr("Level : ");
  my_put_nbr(data->level);
  my_putchar('\n');
  my_putstr("Size : ");
  my_put_nbr(data->sizes.y);
  my_putchar('*');
  show_debugs_s(data);
}

void    show_debug_suite(t_struct_d *data)
{
  if (my_strcmp(data->turn, get_that_key("kcuu1")) == 0)
    {
      my_putstr("Key Turn : ^");
      data->turn[0] = 'E';
    }
  else
    my_putstr("Key Turn : ");
  my_putstr(data->turn);
  my_putchar('\n');
  show_debugs(data);
}

void		show_debug(t_struct_d *data)
{
  my_putstr("*** DEBUG MODE ***\n");
  if (my_strcmp(data->left, get_that_key("kcub1")) == 0)
    {
      my_putstr("Key Left : ^");
      data->left[0] = 'E';
    }
  else
    my_putstr("Key Left : ");
  my_putstr(data->left);
  my_putchar('\n');
  if (my_strcmp(data->right, get_that_key("kcuf1")) == 0)
    {
      my_putstr("Key Right : ^");
      data->right[0] = 'E';
    }
  else
    my_putstr("Key Right : ");
  my_putstr(data->right);
  my_putchar('\n');
  show_debug_suite(data);
}
