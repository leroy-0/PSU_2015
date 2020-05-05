/*
** send_err.c for send_err in /home/poinss_y/Documents/PSU/PSU_2015_42sh
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Thu May 26 11:29:33 2016 Yan Poinssot
** Last update Thu May 26 11:36:50 2016 Yan Poinssot
*/

#include	"my.h"

int		send_err(char *before, char *after, int back)
{
  my_puterr(before);
  my_puterr(" : ");
  my_puterr(after);
  return (back);
}
