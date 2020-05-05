/*
** key_init_ptrs.c for key_init_ptrs in /home/leroy_0/tek1/PSU_2015_42sh/bonus
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Sun Jun  5 17:37:30 2016 leroy_0
** Last update Sun Jun  5 21:14:27 2016 leroy_0
*/

#include	"bonus.h"
#include	"my.h"

t_ptrs		*init_all_ptrs(t_ptrs *ptrs)
{
  ptrs[0].nb = 3;
  ptrs[0].ptr = &(my_ctrl_c);
  ptrs[1].nb = 12;
  ptrs[1].ptr = &(my_ctrl_l);
  ptrs[2].nb = 27;
  ptrs[2].ptr = &(my_move_cursor);
  ptrs[3].nb = 127;
  ptrs[3].ptr = &(my_backspace);
  ptrs[4].nb = 1;
  ptrs[4].ptr = &(my_ctrl_a);
  ptrs[5].nb = 5;
  ptrs[5].ptr = &(my_ctrl_e);
  ptrs[6].nb = 21;
  ptrs[6].ptr = &(my_ctrl_u);
  ptrs[7].nb = 23;
  ptrs[7].ptr = &(my_ctrl_w);
  ptrs[8].nb = 8;
  ptrs[8].ptr = &(my_backspace);
  ptrs[9].nb = 11;
  ptrs[9].ptr = &(my_ctrl_k);
  ptrs[10].nb = 9;
  ptrs[10].ptr = &(auto_complete);
  ptrs[11].nb = 0;
  return (ptrs);
}

t_ptrs		*init_ptrs()
{
  t_ptrs	*ptrs;

  ptrs = my_x_malloc(sizeof(t_ptrs) * 12);
  ptrs = init_all_ptrs(ptrs);
  return (ptrs);
}

t_ptrs		*init_values(t_cursor *cursor, char **paths)
{
  t_ptrs	*ptrs;

  cursor->x = 0;
  cursor->paths = paths;
  ptrs = init_ptrs();
  return (ptrs);
}
