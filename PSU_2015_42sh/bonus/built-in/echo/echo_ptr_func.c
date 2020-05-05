/*
** echo_ptr_func.c for PSU_2015_42sh in /home/klein-h/rendu/PSU_2015_42sh/built-in/echo/echo_ptr_func.c
**
** Made by Arthur KLEIN
** Login   <arthur.klein@epitech.eu>
**
** Started on  Sat Jun 04 19:15:10 2016 Arthur KLEIN
** Last update Sat Jun 04 19:15:10 2016 Arthur KLEIN
*/

#include	<unistd.h>
#include	"my.h"

void		print_a_echo(void)
{
  my_putchar('\a');
}

void		print_b_echo(void)
{
  my_putchar('\b');
}

void		print_e_echo(void)
{
  my_putchar('\e');
}

void		print_f_echo(void)
{
  my_putchar('\f');
}
