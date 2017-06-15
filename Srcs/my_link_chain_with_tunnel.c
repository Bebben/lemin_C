/*
** my_link_chain_with_tunnel.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Apr 11 15:01:28 2017 Enguerrand Arminjon
** Last update Fri Apr 28 09:14:58 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "graph.h"
#include "my.h"
#include "my_error.h"
#include "lemin.h"

int		find_tunnel(char *str)
{
  int		i;
  char		sep;

  sep = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '-')
	sep++;
      else if ((str[i] == '-' && (i == 0 || str[i + 1] == '\0'))
	       || str[i] == ' ' || str[i] == '\t')
	return (1);
      i++;
    }
  return (sep == 1 ? 0 : 1);
}

t_node		*my_get_node(t_node *node, char *name)
{
  t_node	*tmp;
  t_node	*result;
  int		nb;

  nb = 1;
  tmp = node;
  if (name == NULL)
    return (NULL);
  while (tmp->next  != NULL && (nb = my_strcmp(tmp->name, name) != 0))
    tmp = tmp->next;
  if (nb == 0)
    {
      result = tmp;
      return (result);
    }
  my_puterror("ERROR: Node not found.\n", 2, 84);
  return (NULL);
}

int		parsing_tunnel(char **tab, int i, t_node *node, t_graph *graph)
{
  t_node	*tmp_f;
  t_node	*tmp_s;
  char		*tmp1;
  char		*tmp2;

  tmp_s = NULL;
  tmp_f = NULL;
  if ((my_firststr(tab[i], '#')) == 0 && (find_tunnel(tab[i]) == 0))
    {
      tmp1 = my_first_house(tab[i]);
      tmp2 = my_second_house(tab[i]);
      if (tmp2 == NULL || tmp1 == NULL)
	return (my_puterror("ERROR: MALLOC FAIL\n", 2 , 1));
      if (((tmp_f = my_get_node(node, tmp1)) == NULL)
	  || ((tmp_s = my_get_node(node, tmp2)) == NULL))
	return (1);
      my_printf("%s-%s\n", tmp1, tmp2);
      add_edge(graph, tmp_f, tmp_s);
      free(tmp1);
      free(tmp2);
    }
  return (0);
}

int		my_link_chain_with_tunnel(char **tab, t_node *node,
					  t_lemin *lemin, t_graph *graph)
{
  int		i;

  i = 0;
  if ((debug_position_node(node)) == 1)
    return (1);
  while (tab[i] != NULL && (find_tunnel(tab[i]) == 1))
    i++;
  if ((debug_start(lemin, node, &tab[i], -1)) == 1)
    return (1);
  my_putstr("#tunnels\n");
  while (tab[i] != NULL)
    {
      if ((parsing_tunnel(tab, i, node, graph)) == 1)
	return (1);
      i++;
    }
  return (0);
}
