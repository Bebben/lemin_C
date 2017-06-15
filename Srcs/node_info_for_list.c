/*
** node_info_for_list.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Apr 11 13:46:11 2017 Enguerrand Arminjon
** Last update Fri Apr 28 09:02:27 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

char		*node_name(char *str, int *i)
{
  char		*name;
  int		a;

  if (str == NULL ||
      (name = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[*i] != '\0')
    {
      a = 0;
      if (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '\t')
	{
	  while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '\t')
	    {
	      name[a] = str[*i];
	      a = a + 1;
	      *i = *i + 1;
	    }
	  name[a] = '\0';
	  return (name);
	}
      *i = *i + 1;
    }
  return (NULL);
}

int		find_nb_str(char *str, int *i)
{
  int		nb;

  nb = COORD_FAIL;
  while (str[*i] != '\0')
    {
      if (str[*i] == '-' || str[*i] == '+'
	  || (str[*i] >= '0' && str[*i] <= '9'))
	{
	  nb = my_getnbr(&str[*i]);
	  while (str[*i] == '-' || str[*i] == '+'
		 || (str[*i] >= '0' && str[*i] <= '9'))
	    *i = *i + 1;
	  return (nb);
	}
      *i = *i + 1;
    }
  return (COORD_FAIL);
}

int		node_coord(char *str, int *i, t_vec *vector)
{
  int		nb;

  while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '\t')
    *i = *i + 1;
  if ((nb = find_nb_str(str, i)) != COORD_FAIL)
    vector->x = nb;
  if (nb != COORD_FAIL && (nb = find_nb_str(str, i)) != COORD_FAIL)
    vector->y = nb;
  return (nb == COORD_FAIL ? my_puterror("ERROR: COORD FAIL !\n", 2, 1) : 0);
}

int		take_info(char *str, t_node *node, int on, t_lemin *lemin)
{
  static int	nb_list = 0;
  int		i;

  i = 0;
  if (((node->name = node_name(str, &i)) == NULL)
      || ((node_coord(str, &i, &node->coord)) == 1))
    return (1);
  node->nb = nb_list;
  if (on == 0)
    {
      nb_list++;
      lemin->nb_node = nb_list;
    }
  return (0);
}
