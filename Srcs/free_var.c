/*
** free_var.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Tue Apr 11 12:03:46 2017 Enguerrand Arminjon
** Last update Tue Apr 11 12:08:26 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "lemin.h"
#include "graph.h"
#include "my.h"

void	free_var(t_lemin *lemin, t_node *node, t_graph *graph, char **tab)
{
  free(lemin->start.name);
  free(lemin->end.name);
  free_list(node);
  free_graph(graph);
  free_tab(tab);
}
