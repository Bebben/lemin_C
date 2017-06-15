/*
** graph.h for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Apr 24 13:15:25 2017 Enguerrand Arminjon
** Last update Mon Apr 24 13:25:32 2017 Enguerrand Arminjon
*/

#ifndef GRAPH_H_
# define GRAPH_H_

typedef struct		s_tabs
{
  int			*save;
  int			**path;
  int			j;
  int			index;
}			t_tabs;

typedef struct		s_node2
{
  char			*name;
  char			*dest;
  int			nb;

  struct s_node2	*next;
}			t_node2;

typedef struct		s_list
{
  int			visited;
  int			nb_ant;

  struct s_node2	*head;
}			t_list;

typedef struct		s_graph
{
  int			v;

  struct s_list		*arr;
}			t_graph;

#endif /* !GRAPH_H_ */
