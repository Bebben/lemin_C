/*
** int_to_string.c for  in /home/armin.pc/delivery/CPE_2016_matchstick/bonus
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Feb 16 17:41:44 2017 Enguerrand Arminjon
** Last update Tue Mar 14 09:07:51 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	*int_to_str(int nb)
{
  int	tmp;
  int	len;
  char	*str;

  tmp = nb;
  len = 0;
  while (tmp > 0)
    {
      tmp /= 10;
      len++;
    }
  if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
    return (NULL);
  str[len] = '\0';
  while (len--)
    {
      str[len] = nb % 10  + '0';
      nb /= 10;
    }
  return (str);
}
