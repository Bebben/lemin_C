/*
** free_graph.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Tue Apr 11 11:41:16 2017 Enguerrand Arminjon
** Last update Tue Apr 11 15:29:42 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "graph.h"

void		*free_graph_list(t_node2 *list)
{
  t_node2	*tmp;

  while (list != NULL)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
  return (NULL);
}

int		free_graph(t_graph *graph)
{
  int		i;

  i = 0;
  if (graph != NULL)
    {
      while (i < graph->v)
	{
	  free_graph_list(graph->arr[i].head);
	  i = i + 1;
	}
      free(graph->arr);
      free(graph);
    }
  return (0);
}
