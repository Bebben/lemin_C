/*
** debug_position_node.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Mon Apr 10 15:34:27 2017 Enguerrand Arminjon
** Last update Thu Apr 13 09:25:50 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"

int		debug_position_node(t_node *node)
{
  t_node	*tmp;
  t_node	*tmp_2;

  tmp = node;
  while (tmp != NULL)
    {
      tmp_2 = tmp->next;
      while (tmp_2 != NULL && tmp_2->name != NULL)
	{
	  if (tmp->coord.x == tmp_2->coord.x && tmp->coord.y == tmp_2->coord.y)
	    return (my_puterror("ERROR: WITH POSITION\n", 2, 1));
	  else if (my_strcmp(tmp->name, tmp_2->name) == 0)
	    return (my_puterror("ERROR: 2 HOUSES HAVE THE SAME NAME\n", 2, 1));
	  tmp_2 = tmp_2->next;
	}
      tmp = tmp->next;
    }
  return (0);
}
