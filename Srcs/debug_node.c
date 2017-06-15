/*
** debug_node.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Tue Apr 11 15:02:55 2017 Enguerrand Arminjon
** Last update Tue Apr 11 15:03:35 2017 Enguerrand Arminjon
*/

#include "lemin.h"
#include "my.h"

int	debug_info_node(t_node *node)
{
  if (node == NULL || node->name == NULL
      || node->coord.x == -1 || node->coord.y == -1)
    return (1);
  return (0);
}

int	my_debug_node(t_lemin *lemin)
{
  if ((debug_info_node(&lemin->start) == 1)
      ||  ((debug_info_node(&lemin->end)) == 1))
    return (1);
  return (0);
}
