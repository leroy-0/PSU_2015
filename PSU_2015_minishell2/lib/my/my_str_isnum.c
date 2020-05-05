/*
** my_str_isnum.c for my_str_isnum in 
** 
** Made by leroy_0
** Login   <leroy_0@epitech.net>
** 
** Started on  Thu Apr 21 09:45:17 2016 leroy_0
** Last update Thu Apr 21 09:45:18 2016 leroy_0
*/

int	my_str_isnum(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] <= '9' && str[a] >= '0')
	a++;
      else
	return (0);
    }
  if (str[a] == '\0')
    return (1);
  return (0);
}
