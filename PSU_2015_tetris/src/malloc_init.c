/*
** malloc_init.c for malloc_init in
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Sun Mar 20 01:53:39 2016 Tekm
** Last update Sun Mar 20 01:53:47 2016 Tekm
*/
#include "../include/my.h"
#include "../include/tetris.h"

char    **malloc_init(char **tabs, t_struct_d *data)
{
  int   i;
  int j;

  i = 0;
  j = 0;
  tabs = malloc(sizeof(char *) * (data->sizes.y + 1));
  while (i <= data->sizes.y)
    {
      tabs[i++] = malloc(sizeof(char) * (data->sizes.x + 1));
    }
  i = 0;
  j = 0;
  while (i < data->sizes.y)
    {
      while (j <data->sizes.x)
        tabs[i][j++] = '0';
      tabs[i][j] = '\0';
      j = 0;
      i++;
    }
  tabs[i] = NULL;
  return (tabs);
}
