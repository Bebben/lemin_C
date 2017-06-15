/*
** algo.c for lemin in /home/benoit.pingris/save/CPE_2016_Lemin/Srcs
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Fri Apr  7 20:12:28 2017 benoit pingris
** Last update Thu Apr 27 10:36:38 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_error.h"
#include "my.h"
#include "graph.h"

int		stock_path(t_tabs *tabs, int i, int end)
{
  tabs->path[tabs->index][i++] = end;
  tabs->path[tabs->index++][i] = -1;
  tabs->j--;
  return (SUCCESS);
}

void		find_path(t_graph *graph, int nb, int end, t_tabs *tabs)
{
  t_node2	*node;
  int		i;

  graph->arr[nb].visited = 1;
  node = graph->arr[nb].head;
  tabs->save[tabs->j++] = nb;
  while (node)
    {
      if (graph->arr[node->nb].visited == 0)
	{
	  if (node->nb == end)
	    {
	      i = -1;
	      tabs->save[tabs->j++] = end;
	      while (tabs->save[++i] != end)
		tabs->path[tabs->index][i] = tabs->save[i];
	      stock_path(tabs, i, end);
	    }
	  else
	    find_path(graph, node->nb, end, tabs);
	}
      node = node->next;
    }
  tabs->j--;
}

int		nb_tab(int *tab, int end)
{
  int		i;

  i = 0;
  while (tab[i] != end)
    ++i;
  return (i + 1);
}

int		short_path(t_tabs *tab, int end)
{
  int		i;
  int		save;
  int		min;
  int		old;

  i = 0;
  old = 999999;
  while (i < tab->index)
    {
      save = nb_tab(tab->path[i], end);
      if (save < old)
	min = i;
      ++i;
    }
  return (min);
}

void		print_path(t_tabs *tab, int end)
{
  int		i;
  int		j;

  i = 0;
  short_path(tab, end);
  while (i < tab->index)
    {
      j = 0;
      while (tab->path[i][j] != -1)
	my_printf("%d -> ", tab->path[i][j++]);
      my_printf("\n");
      ++i;
    }
}
