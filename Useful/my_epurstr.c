/*
** my_epurstr.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Thu Apr 13 11:11:56 2017 Enguerrand Arminjon
** Last update Thu Apr 13 11:18:15 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char	*my_epurstr(char *s)
{
  int	i;
  int	a;
  char	*new;

  i = 0;
  a = 0;
  if (s == NULL || (new = malloc(sizeof(char) * (my_strlen(s) + 1))) == NULL)
    return (NULL);
  new[0] = '\0';
  while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
    i++;
  if (s[i] != '\0')
    {
      while (s[i] != '\0')
	new[a++] = s[i++];
      new[a] = '\0';
    }
  free(s);
  return (new);
}
