/*
** my_str_isupper.c for my_str_isupper in /home/leroy_0/rendu/Piscine_C_J07/lib/my
** 
** Made by maxime leroy
** Login   <leroy_0@epitech.net>
** 
** Started on  Wed Oct  7 13:04:00 2015 maxime leroy
** Last update Sat Oct 17 14:52:18 2015 maxime leroy
*/

int	my_str_isupper(char *str)
{
  int a;

  a = 0;
  while (str[a] != '\0')
    {
      if (str[a] <= 'Z' && str[a] >= 'A')
        a++;
      else
        return (0);
    }
  if (str[a] == '\0')
    return (1);
}
