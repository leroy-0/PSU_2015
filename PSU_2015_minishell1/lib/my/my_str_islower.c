/*
** my_str_islower.c for my_str_islower in /home/leroy_0/rendu/Piscine_C_J07/lib/my
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Wed Oct  7 13:02:57 2015 maxime leroy
** Last update Sat Oct 17 14:47:08 2015 maxime leroy
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
}
