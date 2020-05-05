/*
** start_history.c for history in /home/longle_h/rendu/PSU_2015_42sh/bonus/history
**
** Made by Henri LONGLE
** Login   <longle_h@epitech.net>
**
** Started on  Sat Jun  4 13:42:02 2016 longle_h
** Last update Sun Jun  5 18:42:49 2016 bruere_s
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<sys/stat.h>
#include	<sys/types.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>
#include	"../include/get_next_line.h"

int		verif_file(char *file)
{
  if ((access(file, F_OK)) != 0)
    return (2);
  if ((access(file, R_OK)) != 0)
    {
      return (1);
    }
  if ((access(file, W_OK)) != 0)
    {
      return (1);
    }
  return (0);
}

int		open_file_sh(int mode, char *file)
{
  int		res;
  int		fd;

  res = verif_file(file);
  if (res == 1)
    return (-1);
  else if (res == 2)
    {
      if ((fd = open(file, O_CREAT | O_RDWR,
		     S_IRUSR | S_IWUSR)) < 0)
	{
	  strerror(errno);
	  return (-1);
	}
    }
  else if (mode == 1)
    fd = open(file, O_RDONLY);
  else if (mode == 2)
    fd = open(file, O_WRONLY | O_APPEND);
  return (fd);
}

char		**read_tab(int fd, char **hist)
{
  int		i;
  char		*str;

  i = 1;
  while ((str = get_next_line(fd)) != NULL)
    {
      if ((hist = realloc(hist, sizeof(char *) * (i + 1))) == NULL)
	return (NULL);
      hist[i - 1] = strdup(str);
      hist[i] = NULL;
      i++;
      free(str);
    }
  return (hist);
}

char		**gimme_hist(void)
{
  char		**hist;
  int		fd;

  hist = NULL;
  if ((fd = open_file_sh(1, ".42_history")) == -1)
    return (NULL);
  if ((hist = read_tab(fd, hist)) == NULL)
    return (NULL);
  close(fd);
  return (hist);
}
