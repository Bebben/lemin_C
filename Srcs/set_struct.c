/*
** set_struct.c for lemin in /home/benoit.pingris/save/CPE_2016_Lemin
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Mon Apr 10 21:33:57 2017 benoit pingris
** Last update Thu Apr 27 11:31:43 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my_error.h"
#include "lemin.h"
#include "graph.h"

int	set_tabs(t_tabs *tab, int node)
{
  int	i;

  i = 0;
  tab->index = 0;
  tab->j = 0;
  while (i < node * node)
    {
      if ((tab->path[i] = malloc(sizeof(int) * (node * 2) + 1)) == NULL)
	return (ERROR);
      ++i;
    }
  tab->path[i] = NULL;
  return (SUCCESS);
}
