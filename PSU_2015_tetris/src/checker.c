/*
** checker.c for checker in /home/tekm/tek1/PSU_2015_tetris
**
** Made by Tekm
** Login   <tekm@epitech.net>
**
** Started on  Sun Mar 20 19:14:19 2016 Tekm
** Last update Sun Mar 20 19:20:32 2016 Tekm
*/

#include "../include/my.h"
#include "../include/tetris.h"

void            load_tetriminos(int fd, char *str, char **tetrimino_order)
{
  char                  *path;
  int                   cpt;

  cpt = 0;
  while (tetrimino_order[cpt])
    {
      path = malloc(sizeof(char)
                    * (my_strlen(str) + my_strlen(tetrimino_order[cpt]) + 1));
      path = my_strcpy(path, str);
      path = my_strcat(path, tetrimino_order[cpt]);
      fd = open(path, O_RDONLY);
      check_tetrimino(fd, tetrimino_order[cpt], path, 0);
      free(path);
      cpt++;
    }
}

char                    **get_tetri(char **tetrimino_order, int cpt, char *tmp)
{
  tmp = malloc(sizeof(char) * my_strlen(tetrimino_order[cpt + 1]) + 1);
  tmp = my_strcpy(tmp, tetrimino_order[cpt + 1]);
  tetrimino_order[cpt + 1] = malloc(sizeof(char)
                                    * my_strlen(tetrimino_order[cpt]) + 1);
  tetrimino_order[cpt + 1] =
    my_strcpy(tetrimino_order[cpt + 1], tetrimino_order[cpt]);
  tetrimino_order[cpt] = malloc(sizeof(char) * my_strlen(tmp) + 1);
  tetrimino_order[cpt] = my_strcpy(tetrimino_order[cpt], tmp);
  return (tetrimino_order);
}

char                    **get_tetrimin(char **tetrimino_order, char *tmp,
                                       int order, int cpt)
{
  while (tetrimino_order[cpt])
    {
      cpt = 0;
      order = 0;
      while (tetrimino_order[cpt] && order == 0)
        {
          if (tetrimino_order[cpt + 1]
              && my_strcmp(tetrimino_order[cpt],
			   tetrimino_order[cpt + 1]) == 1)
            {
              tetrimino_order = get_tetri(tetrimino_order, cpt, tmp);
              order = 1;
            }
          if (order == 1)
            {
              cpt = 0;
              order = 0;
            }
          else
            cpt++;
        }
    }
  tetrimino_order[cpt] = NULL;
  return (tetrimino_order);
}

char                    **order_it(char **tetrimino_order)
{
  char          *tmp;
  int           order;
  int           cpt;

  cpt = 0;
  order = 0;
  tmp = NULL;
  tetrimino_order = get_tetrimin(tetrimino_order, tmp, order, cpt);
  return (tetrimino_order);
}

char                    *get_file_name(const char *str)
{
  char          *tetri;
  int           savecpt;
  int           cpt_c;
  int           cpt;

  cpt = 0;
  tetri = ".tetrimino";
  cpt = my_strlen((char *)str);
  cpt_c = my_strlen(tetri);
  savecpt = cpt_c;
  while (cpt >= my_strlen((char *)str) - savecpt)
    {
      cpt_c--;
      cpt--;
    }
  cpt_c = 0;
  while (cpt_c <= cpt)
    my_putchar(str[cpt_c++]);
  return (NULL);
}
