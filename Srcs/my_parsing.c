/*
** my_parsing.c for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Apr 11 14:57:57 2017 Enguerrand Arminjon
** Last update Fri Apr 28 10:53:53 2017 Enguerrand Arminjon
*/

#include <stdlib.h>
#include "my.h"
#include "lemin.h"
#include "my_error.h"

int		find_node(char **tab, t_lemin *lemin, int i)
{
  static int	s = 0;
  static int	e = 0;

  if ((my_strcmp(tab[i], "##start")) == 0)
    {
      my_putstr("##start\n");
      if ((take_info(tab[i + 1], &lemin->start, 1, lemin)) == 1)
	return (1);
      s = s + 1;
    }
  else if ((my_strcmp(tab[i], "##end")) == 0)
    {
      my_putstr("##end\n");
      if ((take_info(tab[i + 1], &lemin->end, 1, lemin)) == 1)
	return (1);
      e = e + 1;
    }
  return ((e > 1 || s > 1) ? 1 : 0);
}

int		my_list_node(char *str)
{
  int		i;
  int		argu;
  int		size;

  size = my_strlen(str);
  i = 0;
  argu = 0;
  while (i < size)
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
	    i++;
	  argu++;
	}
      i++;
    }
  return (argu == 3 ? 0 : 1);
}

int		create_new_chain(t_node *node)
{
  t_node	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (84);
  tmp->name = NULL;
  tmp->next = NULL;
  tmp->coord = my_vector(COORD_FAIL, COORD_FAIL);
  node->next = tmp;
  return (0);
}

int		get_nb_ant(char **tab)
{
  int		i;
  int		j;
  int		nb;

  i = -1;
  while (tab[++i] != '\0')
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  while (tab[i][j] == ' ' || tab[i][j] == '\t')
	    j++;
	  if (tab[i][j] != '\0'
	      && ((tab[i][j] >= '0' && tab[i][j] <= '9') || tab[i][j] == '-'
		  || tab[i][j] == '+'))
	    {
	      nb = my_getnbr(&tab[i][j]);
	      my_printf("#number_of_ants\n%i\n", nb);
	      return (nb <= 0 ? my_puterror("ERROR: ANY ANT(s)\n", 2, 84) : nb);
	    }
	  j++;
	}
    }
  return (my_puterror("ERROR: ANY ANT(s) !\n", 2, 84));
}

int		my_parsing(char **tab, t_lemin *lem, t_node *node)
{
  t_node	*tmp;
  int		i;

  i = 0;
  if ((lem->ant = get_nb_ant(tab)) == 84)
    return (1);
  tmp = node;
  my_putstr("#rooms\n");
  while (tab[++i] != NULL)
    {
      if (tab[i][0] == '#' && tab[i][1] == '#'
	  && ((find_node(tab, lem, i)) == 1))
	return (1);
      else if ((my_list_node(tab[i])) == 0)
	{
	  if (((take_info(tab[i], tmp, 0, lem)) == ERROR)
	      || ((create_new_chain(tmp)) == ERROR))
	    return (ERROR);
	  my_putstr(tmp->name);
	  my_printf(" %i %i\n", tmp->coord.x, tmp->coord.y);
	  tmp = tmp->next;
	  tmp->next = NULL;
	}
    }
  return (my_debug_node(lem));
}
