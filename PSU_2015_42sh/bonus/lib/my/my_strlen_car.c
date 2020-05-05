/*
** my_strlen_car.c for my_strlen_car in /home/bruere_s/Projet/PSU_2015_42sh/bonus
**
** Made by Sebastien BRUERE
** Login  <bruere_s@epitech.net>
**
** Started on  Sun Jun  5 22:55:13 2016 bruere_s
** Last update Sun Jun  5 22:55:24 2016 bruere_s
*/

int		my_strlen_car(char *s, char car)
{
  int		i;

  i = 0;
  while (s[i] != car && s[i] != '\0')
    i++;
  if (s[i] == '\0')
    return (-1);
  return (i);
}
