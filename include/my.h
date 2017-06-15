/*
** my.h for  in /home/armin.pc/delivery/CPE/CPE_2016_Lemin
**
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
**
** Started on  Mon Apr 24 13:15:09 2017 Enguerrand Arminjon
** Last update Fri Apr 28 09:16:13 2017 Enguerrand Arminjon
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <stdarg.h>
# include "lemin.h"
# include "graph.h"

/*
** *****
** Project's functions
** *****
*/

char	**file_to_tab(char **tab);
int	find_tunnel(char *str);
void	free_ants(t_ant *);
int	set_up_ants(t_ant **, t_lemin *, int *);
int	my_firststr(char *str, char sep);
int	short_path(t_tabs *my_tabs, int end);
int	set_tabs(t_tabs *tab, int node);
int	init_struct(t_tabs *, int);
int	create_new_chain(t_node *);
void	print_path(t_tabs *, int);
void	find_path(t_graph *, int, int, t_tabs *);
int	take_info(char *str, t_node *node, int one, t_lemin *lemin);
int	my_game(t_graph *graph, t_lemin *lemin, t_tabs *my_tabs);
int	debug_position_node(t_node *node);
int	debug_start(t_lemin *lemin, t_node *node, char **tab, int less_one);
char	*my_first_house(char *str);
char	*my_second_house(char *str);
char	*int_to_str(int nb);
void	disp_node_neighbors(t_graph *, t_node *);
t_node	*my_get_node(t_node *, char *);
void	print_graph(t_graph *);
void	add_edge(t_graph *, t_node *, t_node *);
t_graph	*create_graph(int);
void	check_list(t_node *node, t_lemin *lemin);
int	my_debug_node(t_lemin *lemin);
int	my_link_chain_with_tunnel(char **, t_node *, t_lemin *, t_graph *);
t_vec	my_vector(int x, int y);
int	my_parsing(char **tab, t_lemin *lemin, t_node *node);

/*
** Functions for clear var
*/

int	free_var_2(t_tabs *);
void	free_var(t_lemin *, t_node *, t_graph *, char **);
int	free_graph(t_graph *graph);
void	*free_list(t_node *node);

/*
** *****
** Other functions
** *****
*/

char	*my_epurstr(char *str);
int	my_str_isalpha(char *str);
int	my_puterror(char *str, int canal, int return_error);
int	print_tab(char **tab);
char	*get_next_line(int fd);
char	**free_tab(char **tab);
char	my_strcmp(char *str_1, char *str_2);
char	my_strncmp(char *str_1, char *str_2, int nb);
char	my_strcmp_2(char *str_1, char *str_2, char sep);
char	*my_strcat(char *dest, char *src);
char	*my_realloc(char *str, int new_size);
void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_str_isnum(char *str);

/*
** My printf
*/

int	my_printf(char *s, ...);
void	for_my_pitch(int i, int zero);
int	my_size_c(int nb);
void	the_hashtag(char *s, va_list ap, int *a);
void	the_else_print(int *a);
void	the_flags(char *s, va_list ap, int *a);
void	my_octal(long int nb);
int	my_put_short(short nb);
int	my_size(int nb);
void	my_binari(int nb);
void	my_hexadecimal(long int nb);
void	my_hexadecimal_2(long int nb);
int	my_putstr_int(int *str);
int	my_put_long(long int nb);

/*
** My fprintf
*/

int	my_fprintf(char *s, ...);
void	for_my_pitch(int i, int zero);
int	my_fsize_c(int nb);
void	fthe_hashtag(char *s, va_list ap, int *a);
void	fthe_else_print(int *a);
void	fthe_flags(char *s, va_list ap, int *a);
void	my_foctal(long int nb);
int	my_fput_short(short nb);
int	my_fsize(int nb);
void	my_fbinari(int nb);
void	my_fhexadecimal(long int nb);
void	my_fhexadecimal_2(long int nb);
int	my_fputstr_int(int *str);
int	my_fput_long(long int nb);
int	my_fput_nbr(int nb);
int	my_fputstr(char *str);
void	my_fputchar(char c);

#endif /* !MY_H_ */
