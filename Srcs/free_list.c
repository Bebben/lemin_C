/*
** free_list.c for  in /home/armin.pc/delivery/PSU_2016_minishell2
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Thu Mar 23 14:35:12 2017 Enguerrand Arminjon
** Last update Tue Apr 11 11:57:53 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

void		*free_list(t_node *list)
{
  t_node	*tmp;

  while (list != NULL)
    {
      tmp = list->next;
      if (list != NULL)
	free(list->name);
      free(list);
      list = tmp;
    }
  return (NULL);
}
