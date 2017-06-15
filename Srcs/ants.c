/*
** ants.c for lemin in /home/benoit.pingris/delivery/CPE/CPE_2016_Lemin
**
** Made by benoit pingris
** Login   <benoit.pingris@epitech.net>
**
** Started on  Thu Apr 20 11:03:47 2017 benoit pingris
** Last update Thu Apr 27 10:36:55 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "lemin.h"
#include "my_error.h"

int		add_list(t_ant **list, int ant, int pos, int *path)
{
  static int	id;
  t_ant		*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (ERROR);
  tmp->ant = ant - id;
  tmp->current = pos;
  tmp->path = path;
  tmp->next = *list;
  *list = tmp;
  ++id;
  return (SUCCESS);
}

int		set_up_ants(t_ant **ants, t_lemin *lemin, int *dest)
{
  int		i;

  i = 0;
  while (i < lemin->ant)
    {
      if (add_list(ants, lemin->ant, lemin->start.nb, dest) == ERROR)
	return (ERROR);
      ++i;
    }
  return (SUCCESS);
}

void		free_ants(t_ant *ant)
{
  t_ant		*tmp;

  while ((tmp = ant) != NULL)
    {
      ant = ant->next;
      free(tmp);
    }
}
