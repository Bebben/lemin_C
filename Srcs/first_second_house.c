/*
** first_second_house.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Apr 28 09:14:24 2017 Enguerrand Arminjon
** Last update Fri Apr 28 09:17:06 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char		*my_second_house(char *str)
{
  char		*copy;
  int		i;
  int		a;

  a = 0;
  i = 0;
  if (str == NULL
      || (copy = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  copy[0] = '\0';
  if (str[i] != '-' && str[i] != '\0')
    {
      while (str[i] != '-' && str[i] != '\0')
	i = i + 1;
      if (str[i] != '\0')
	i = i + 1;
    }
  while (str[i] != '\0')
    {
      copy[a] = str[i];
      a = a + 1;
      i = i + 1;
    }
  copy[a] = '\0';
  return (copy);
}

char		*my_first_house(char *str)
{
  char		*copy;
  int		i;

  i = 0;
  if (str == NULL ||
      (copy = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  copy[0] = '\0';
  while (str[i] != '\0' && str[i] != '-')
    {
      copy[i] = str[i];
      i++;
    }
  copy[i] = '\0';
  return (copy);
}
