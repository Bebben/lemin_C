/*
** main.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Apr 27 14:25:20 2017 Enguerrand Arminjon
** Last update Fri Apr 28 09:12:49 2017 Enguerrand Arminjon
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "lemin.h"
#include "my_error.h"

t_vec		my_vector(int x, int y)
{
  t_vec		vector;

  vector.x = x;
  vector.y = y;
  return (vector);
}

void		init_var(t_node *node, t_lemin *lemin)
{
  lemin->ant = 0;
  lemin->nb_node = 0;
  node->name = NULL;
  node->next = NULL;
  node->coord = my_vector(COORD_FAIL, COORD_FAIL);
}

int		init_struct(t_tabs *tab, int node)
{
  tab->save = NULL;
  tab->path = NULL;
  tab->j = 0;
  tab->index = 0;
  if (((tab->save = malloc(sizeof(int) * (2 * node + 1))) == NULL)
      || ((tab->path = malloc(sizeof(int *) * (1 + (node * node)))) == NULL)
      || (set_tabs(tab, node) == ERROR))
    return (ERROR);
  return (SUCCESS);
}

int		my_lemin(int nb)
{
  t_tabs	my_tabs;
  t_node	*node;
  t_lemin	lemin;
  t_graph	*graph;
  char		**tab;

  tab = NULL;
  graph = NULL;
  if ((node = malloc(sizeof(*node))) == NULL)
    return (ERROR);
  init_var(node, &lemin);
  if (((tab = file_to_tab(tab)) == NULL)
      || ((my_parsing(tab, &lemin, node)) == 1)
      || ((graph = create_graph(lemin.nb_node)) == NULL)
      || ((init_struct(&my_tabs, lemin.nb_node) == ERROR))
      || ((my_link_chain_with_tunnel(tab, node, &lemin, graph)) != 0))
    return (ERROR);
  find_path(graph, lemin.start.nb, lemin.end.nb, &my_tabs);
  if (my_tabs.index == 0)
    return (my_puterror("ERROR: ANY PATH FOUND !\n", 2, 1));
  if ((my_game(graph, &lemin, &my_tabs)) == 1)
    return (1);
  free_var(&lemin, node, graph, tab);
  free_var_2(&my_tabs);
  return (nb);
}

int		main(int ac, char **av)
{
  int		nb;

  nb = 0;
  if (ac != 0)
    nb = my_lemin(0);
  else
    {
      my_fprintf("Please %s < [file]\n", av[0]);
      return (84);
    }
  return (nb != 0 ? my_puterror("ERROR !\n", 2, 84) : 0);
}
