/*
** binary_convert.c for binary_convert in 
** 
** Made by Tekm
** Login   <tekm@epitech.net>
** 
** Started on  Sun Feb 21 18:30:15 2016 Tekm
** Last update Sun Feb 21 18:31:09 2016 Tekm
*/

#include "../include/my.h"

int             binary_convert(int num)
{
  int   decimal_val;
  int   base;
  int   rem;

  decimal_val = 0;
  base = 1;
  while (num > 0)
    {
      rem = num % 10;
      decimal_val = decimal_val + rem * base;
      num = num / 10 ;
      base = base * 2;
    }
  return (decimal_val);
}
