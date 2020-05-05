/*
** put_error.c for put_error in /home/longle_h/rendu/PSU_2015_42sh
**
** Made by Henri LONGLE
** Login   <longle_h@epitech.net>
**
** Started on  Fri May  6 13:30:39 2016 longle_h
** Last update Tue May 31 12:11:50 2016 longle_h
*/

#include	<string.h>
#include	<unistd.h>

void		puterr(char *str)
{
  write(2, str, strlen(str));
}

void		my_put_not_found(char * name)
{
  if (name)
    write(2, name, strlen(name));
  puterr(": Command not found.\n");
}
