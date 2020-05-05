/*
** stitch.c for stitch in /home/poinss_y/Documents/PSU/PSU_2015_42sh
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Thu May 12 11:09:15 2016 Yan Poinssot
** Last update Sun Jun  5 23:29:54 2016 longle_h
*/

#include	<stdlib.h>
#include	<string.h>
#include	"my.h"

static void	copy_words(char *word, char *words, char *sep, char *back)
{
  int		a;
  int		b;

  a = 0;
  while (word[a] != '\0')
    {
      back[a] = word[a];
      a++;
    }
  b = 0;
  while (sep != NULL && sep[b] != '\0')
    {
      back[a + b] = sep[b];
      b++;
    }
  a = a + b;
  b = 0;
  while (words[b] != '\0')
    {
      back[a + b] = words[b];
      b++;
    }
  back[a + b] = '\0';
}

char		*stitch(char *word, char *words, char *sep)
{
  char		*back;
  int		len;

  if (word == NULL && words == NULL)
    return (NULL);
  if (words == NULL)
    return (strdup(word));
  if (word == NULL)
    return (strdup(words));
  len = my_strlen(word) + my_strlen(words) + my_strlen(sep) + 1;
  if ((back = my_x_malloc(sizeof(char) * (len))) == NULL)
    return (NULL);
  copy_words(word, words, sep, back);
  return (back);
}
