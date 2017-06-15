/*
** lemin.h for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Tue Apr 11 14:56:39 2017 Enguerrand Arminjon
** Last update Fri Apr 28 08:49:39 2017 Enguerrand Arminjon
*/

#ifndef LEMIN_H_
# define LEMIN_H_

# define COORD_FAIL 39979729

typedef struct		s_ant
{
  int			ant;
  int			current;
  int		        *path;

  struct s_ant		*next;
}			t_ant;

typedef struct		s_my_vector
{
  int			x;
  int			y;
}			t_vec;

typedef struct		s_node
{
  t_vec			coord;
  char			*name;
  int			nb;

  struct s_node		*next;
}			t_node;

typedef struct		s_lemin
{
  t_node		start;
  t_node		end;
  int			ant;
  int			nb_node;
}			t_lemin;

#endif /* LEMIN_H_ */
