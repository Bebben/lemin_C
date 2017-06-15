/*
** debug_start.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Apr 10 15:36:01 2017 Enguerrand Arminjon
** Last update Fri Apr 28 09:01:03 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

int		search_node_in_my_list(char *str1, char *str2, t_node *node)
{
  t_node	*tmp;
  int		first;
  int		second;

  first = 0;
  second = 0;
  tmp = node;
  while (tmp != NULL)
    {
      if (tmp->name != NULL)
	{
	  if (my_strcmp(str1, tmp->name) == 0)
	    first++;
	  if (my_strcmp(str2, tmp->name) == 0)
	    second++;
	}
      tmp = tmp->next;
    }
  return ((first == 0 || second == 0) ? 1 : 0);
}

void		debug_end(t_lemin *lemin, char *str1,
			  char *str2, int *error_end)
{
  if ((my_strcmp(lemin->end.name, str1) == 0)
      || (my_strcmp(lemin->end.name, str2) == 0))
    *error_end = 0;
  free(str1);
  free(str2);
}

int		debug_start(t_lemin *lemin, t_node *node, char **tab, int i)
{
  int		error_start;
  int		error_end;
  char		*str1;
  char		*str2;

  error_end = 1;
  error_start = 1;
  while (tab[++i] != NULL)
    {
      if ((my_firststr(tab[i], '#')) == 0 && (find_tunnel(tab[i])) == 0)
	{
	  if (((str1 = my_first_house(tab[i])) == NULL)
	      || ((str2 = my_second_house(tab[i])) == NULL)
	      || ((search_node_in_my_list(str1, str2, node)) != 0))
	    return (my_puterror("ERROR: EMPTY HOUSE OR UNKNOW HOUSE\n", 2 , 1));
	  if ((my_strcmp(lemin->start.name, str1) == 0)
	      || (my_strcmp(lemin->start.name, str2) == 0))
	    error_start = 0;
	  debug_end(lemin, str1, str2, &error_end);
	}
    }
  return (error_start == 0 && error_end == 0 ? 0 :
	  my_puterror("ERROR: START / END : NO LINK WITH OTHER NODE\n", 2, 1));
}
