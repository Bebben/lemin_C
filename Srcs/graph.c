/*
** graph.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Apr 11 15:30:00 2017 Enguerrand Arminjon
** Last update Thu Apr 27 10:37:29 2017 Enguerrand Arminjon
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "graph.h"
#include "lemin.h"
#include "my_error.h"

t_node2		*new_node(char *dest, char *name, int nb)
{
  t_node2	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->dest = dest;
  new->nb = nb;
  new->name = name;
  new->next = NULL;
  return (new);
}

t_graph		*create_graph(int v)
{
  int		i;
  t_graph	*graph;

  i = 0;
  if ((graph = malloc(sizeof(*graph))) == NULL)
    return (NULL);
  graph->v = v;
  if ((graph->arr = malloc(sizeof(t_list) * v)) == NULL)
    return (NULL);
  while (i < v)
    {
      graph->arr[i].nb_ant = 0;
      graph->arr[i].visited = 0;
      graph->arr[i].head = NULL;
      i = i + 1;
    }
  return (graph);
}

void		add_edge(t_graph *graph, t_node *src, t_node *dest)
{
  t_node2	*new;

  new = new_node(dest->name, src->name, dest->nb);
  new->next = graph->arr[src->nb].head;
  graph->arr[src->nb].head = new;
  new = new_node(src->name, dest->name, src->nb);
  new->next = graph->arr[dest->nb].head;
  graph->arr[dest->nb].head = new;
}

void		disp_node_neighbors(t_graph *graph, t_node *my_node)
{
  t_node2	*node;

  node = graph->arr[my_node->nb].head;
  while (node)
    node = node->next;
}

void		print_graph(t_graph *graph)
{
  t_node2	*node;
  int		v;

  v = 0;
  while (v < graph->v)
    {
      node = graph->arr[v].head;
      if (node)
	{
	  while (node->next)
	    {
	      node = node->next;
	    }
	  node = node->next;
	}
      ++v;
    }
}
