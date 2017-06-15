/*
** my_firststr.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Apr 13 10:53:09 2017 Enguerrand Arminjon
** Last update Thu Apr 13 10:58:32 2017 Enguerrand Arminjon
*/

#include <stdlib.h>

int	my_firststr(char *str, char sep)
{
  int	i;

  i = 0;
  if (str != NULL && str[i] != '\0' && (str[i] == ' ' || str[i] != '\t'))
    {
      while (str[i] == ' ' || str[i] == '\t')
	i++;
      if (str[i] == sep)
	return (1);
    }
  return (0);
}
