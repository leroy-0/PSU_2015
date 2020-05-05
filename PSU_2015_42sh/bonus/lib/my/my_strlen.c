/*
** my_strlen.c for my_strlen in /home/leroy_0/tek1/PSU_2015_42sh
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Fri Jun  3 00:08:37 2016 leroy_0
** Last update Fri Jun  3 00:08:58 2016 leroy_0
*/

int	my_strlen(char *str)
{
  int	len;

  len = 0;
  while (str && str[len])
    len++;
  return (len);
}
