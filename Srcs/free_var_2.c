/*
** free_var_2.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Apr 11 15:58:23 2017 Enguerrand Arminjon
** Last update Thu Apr 27 11:30:32 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "graph.h"

void	free_int_tab(t_tabs *tab)
{
  int	i;

  i = 0;
  if (tab->path != NULL)
    {
      while (tab->path[i] != NULL)
	{
	  free(tab->path[i]);
	  ++i;
	}
      free(tab->path);
    }
}

int	free_var_2(t_tabs *tab)
{
  free(tab->save);
  free_int_tab(tab);
  return (0);
}
