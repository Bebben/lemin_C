##
## Makefile for  in /home/armin.pc/delivery/CPE_2016_Lemin
##
## Made by Enguerrand Arminjon
## Login   <armin.pc@epitech.net>
##
## Started on  Mon Apr  3 16:56:42 2017 Enguerrand Arminjon
## Last update Fri Apr 28 09:16:58 2017 Enguerrand Arminjon
##


SRCS 	=	Useful/my_putstr.c			\
		Useful/my_putchar.c			\
		Useful/my_put_nbr.c			\
		Useful/my_getnbr.c			\
		Useful/my_revstr.c			\
		Useful/printf/my_printf.c		\
		Useful/printf/my_printf2.c		\
		Useful/printf/my_printf3.c		\
		Useful/printf/my_printf4.c		\
		Useful/printf/my_put_short.c		\
		Useful/printf/my_put_long.c		\
		Useful/fprintf/my_fprintf.c		\
		Useful/fprintf/my_fprintf2.c		\
		Useful/fprintf/my_fprintf3.c		\
		Useful/fprintf/my_fprintf4.c		\
		Useful/fprintf/my_fput_short.c		\
		Useful/fprintf/my_fput_long.c		\
		Useful/fprintf/my_fputchar.c		\
		Useful/fprintf/my_fputstr.c		\
		Useful/fprintf/my_fput_nbr.c		\
		Useful/print_tab.c			\
		Useful/my_strcat.c			\
		Useful/my_strcmp.c			\
		Useful/my_strcmp_2.c			\
		Useful/my_str_isalpha.c			\
		Useful/my_str_isnum.c			\
		Useful/free_my_tab.c			\
		Useful/free_tab.c			\
		Useful/my_realloc.c			\
		Useful/get_next_line.c			\
		Useful/my_puterror.c			\
		Useful/my_strncmp.c			\
		Useful/my_strstr.c			\
		Useful/my_epurstr.c			\
		Srcs/my_parsing.c			\
		Srcs/ants.c				\
		Srcs/my_link_chain_with_tunnel.c	\
		Srcs/free_list.c			\
		Srcs/debug_node.c			\
		Srcs/graph.c				\
		Srcs/algo.c				\
		Srcs/set_struct.c			\
		Srcs/int_to_string.c			\
		Srcs/debug_position_node.c		\
		Srcs/debug_start.c			\
		Srcs/my_game.c				\
		Srcs/free_graph.c			\
		Srcs/free_var.c				\
		Srcs/free_var_2.c			\
		Srcs/node_info_for_list.c		\
		Srcs/my_firststr.c			\
		Srcs/file_to_tab.c			\
		Srcs/first_second_house.c		\
		Srcs/main.c

OBJS 	=  	$(SRCS:.c=.o)

CFLAGS 	+=	-I include -Wall -Wextra -g3

LDFLAGS +=	-I include

NAME 	=	lem_in

CC	= 	gcc

$(NAME): 	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

all:		$(NAME)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
