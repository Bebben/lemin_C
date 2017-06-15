/*
** file_to_tab.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Fri Apr 28 09:12:07 2017 Enguerrand Arminjon
** Last update Fri Apr 28 09:13:48 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

char		**my_put_in_tab(char *str, char **tab)
{
  static int	i = 0;
  char		**new;
  int		j;

  j = 0;
  if ((new = malloc(sizeof(char *) * (i + 2))) == NULL)
    return (NULL);
  while (j < i)
    {
      new[j] = tab[j];
      j++;
    }
  if ((new[j] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  new[j][0] = '\0';
  new[j] = my_strcat(new[j], str);
  new[j + 1] = NULL;
  i++;
  free(tab);
  return (new);
}

char		**file_to_tab(char **tab)
{
  char		*s;

  while ((s = get_next_line(0)) != NULL)
    {
      if ((s = my_epurstr(s)) == NULL)
	return (NULL);
      if ((tab = my_put_in_tab(s, tab)) == NULL)
	return (NULL);
      free(s);
    }
  return (tab);
}
