/*
** my_printf3.c for  in /home/armin.pc/delivery/PSU_2016_my_printf
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Wed Nov 16 13:47:41 2016 Enguerrand Arminjon
** Last update Wed Mar 29 16:36:07 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

void		fthe_zero(char *s, va_list ap, int *a)
{
  va_list	new;
  int		i;
  char		*copy;
  int		zero;

  i = 0;
  *a = *a + 1;
  zero = 0;
  va_copy(new, ap);
  copy = malloc(sizeof(char) * my_strlen(s));
  while (s[*a] <= '9' && s[*a] >= '0')
    {
      copy[i] = s[*a];
      i++;
      *a = *a + 1;
    }
  zero = my_getnbr(copy) - my_size(va_arg(new, int));
  while (zero > 0)
    {
      my_fputchar('0');
      zero--;
    }
}

void		fthe_before_space(char *s, va_list ap, int *a)
{
  va_list	new;
  int		i;
  char		*copy;
  int		zero;

  i = 0;
  zero = 0;
  va_copy(new, ap);
  copy = malloc(sizeof(char) * my_strlen(s));
  while (s[*a] <= '9' && s[*a] >= '0')
    {
      copy[i] = s[*a];
      i++;
      *a = *a + 1;
    }
  zero = my_getnbr(copy) - my_fsize(va_arg(new, int));
  while (zero > 0)
    {
      my_fputchar(' ');
      zero--;
    }
}

void		fthe_before_space_2(char *s, va_list ap, int *a)
{
  va_list	new;
  int		zero;
  int		size;
  int		nb;

  zero = 0;
  va_copy(new, ap);
  va_arg(ap, int);
  nb = va_arg(new, int);
  if (s[*a] == 's')
    size = my_strlen(va_arg(new, char *));
  if (s[*a] == 'i')
    size = my_fsize(va_arg(new, int));
  if (s[*a] == 'c')
    size = 1;
  zero = nb - size;
  while (zero > 0)
    {
      my_fputchar(' ');
      zero--;
    }
}

void		fthe_spaces_print(char *s, va_list ap, int *a)
{
  va_list	new;
  int		i;
  char		*copy;
  int		zero;

  i = 0;
  *a = *a + 1;
  zero = 0;
  va_copy(new, ap);
  copy = malloc(sizeof(char) * my_strlen(s));
  my_fput_nbr(va_arg(ap, long int));
  while (s[*a] <= '9' && s[*a] >= '0')
    {
      copy[i] = s[*a];
      i++;
      *a = *a + 1;
    }
  *a = *a - 1;
  zero = my_getnbr(copy) - my_fsize(va_arg(new, int));
  while (zero > 0)
    {
      my_fputchar(' ');
      zero--;
    }
}

void		fthe_flags(char *s, va_list ap, int *a)
{
  va_list	new;

  va_copy(new, ap);
  if (s[*a] == '+')
    {
      if (va_arg(new, int) >= 0)
	my_fputchar('+');
      *a = *a + 1;
    }
  else if (s[*a - 1] == ' ' && s[*a] != 's' && s[*a] != 'S')
    my_fputchar(' ');
  else if (s[*a] == '#')
    fthe_hashtag(s, ap, a);
  else if (s[*a] == '0')
    fthe_zero(s, ap, a);
  else if (s[*a] <= '9' && s[*a] >= '1')
    fthe_before_space(s, ap, a);
  else if (s[*a] == '-')
    fthe_spaces_print(s, ap, a);
  else if (s[*a] == '*')
    {
      *a = *a + 1;
      fthe_before_space_2(s, ap, a);
    }
}
