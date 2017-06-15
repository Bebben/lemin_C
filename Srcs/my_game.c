/*
** my_game.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Apr 24 13:13:02 2017 Enguerrand Arminjon
** Last update Fri Apr 28 09:09:34 2017 Enguerrand Arminjon
*/

#include "lemin.h"
#include "my.h"

int		get_next_pos(int *path, int curr)
{
  int		i;

  i = 0;
  while (path[i] != -1)
    {
      if (path[i] == curr)
	return (path[i + 1]);
      ++i;
    }
  return (-1);
}

int		my_game_algo(t_ant **ants, t_lemin *lemin, t_graph *graph)
{
  static int	loop;
  t_ant		*tmp;

  tmp = *ants;
  ++loop;
  while (tmp && tmp->ant - 1 != loop)
    {
      tmp->current = get_next_pos(tmp->path, tmp->current);
      my_printf("P%i-%s", tmp->ant, graph->arr[tmp->current].head->name);
      if (tmp->next && tmp->next->ant - 1 != loop)
	my_printf(" ");
      if (tmp->current == lemin->end.nb)
	{
	  tmp = tmp->next;
	  free(*ants);
	  *ants = tmp;
	}
      else
	tmp = tmp->next;
    }
  my_putchar('\n');
  if (*ants == NULL)
    return (1);
  else
    return (0);
}

int		my_game(t_graph *graph, t_lemin *lemin, t_tabs *my_tabs)
{
  t_ant		*ants;

  ants = NULL;
  set_up_ants(&ants, lemin, my_tabs->path[short_path(my_tabs, lemin->end.nb)]);
  graph->arr[lemin->start.nb].nb_ant = lemin->ant;
  my_putstr("#moves\n");
  while (my_game_algo(&ants, lemin, graph) == 0);
  free_ants(ants);
  return (0);
}
