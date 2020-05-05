/*
** my_str_islower.c for my_str_islower in
**
** Made by leroy_0
** Login   <leroy_0@epitech.net>
**
** Started on  Thu Apr 21 09:44:32 2016 leroy_0
** Last update Thu Apr 21 09:44:42 2016 leroy_0
*/

int	my_str_islower(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] <= 'z' && str[a] >= 'a')
        a++;
      else
        return (0);
    }
  if (str[a] == '\0')
    return (1);
  return (0);
}
