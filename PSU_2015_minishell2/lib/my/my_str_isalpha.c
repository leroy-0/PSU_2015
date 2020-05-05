/*
** my_str_isalpha.c for my_str_isalpha in 
** 
** Made by leroy_0
** Login   <leroy_0@epitech.net>
** 
** Started on  Thu Apr 21 09:45:41 2016 leroy_0
** Last update Thu Apr 21 09:46:27 2016 leroy_0
*/

int	my_str_isalpha(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      if ((str[a] <= 'z' && str[a] >= 'a') || (str[a] <= 'Z' && str[a] >= 'A'))
	a++;
      else
	return (0);
    }
  if (str[a] == '\0')
    return (1);
  return (0);
}
