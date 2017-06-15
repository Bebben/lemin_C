/*
** my_strstr.c for  in /home/armin.pc/delivery/CPool_Day06
** 
** Made by Enguerrand Arminjon
** Login   <armin.pc@epitech.net>
** 
** Started on  Mon Oct 10 17:09:59 2016 Enguerrand Arminjon
** Last update Thu Apr 13 11:05:32 2017 Enguerrand Arminjon
*/

#include "my.h"

char	*my_strstr(char *str, char *to_find)
{
  int	a;
  int	b;
  int	find;

  a = 0;
  b = 0;
  while (str[a] != '\0')
    {
      if (to_find[0] == str[a])
	{
	  find = b;
	  while (to_find[b] == str[a])
	    {
	      if (to_find[b + 1] == '\0')
		{
		  return (&str[find]);
		}
	      a = a + 1;
	      b = b + 1;
	    }
	}
      b = 0;
      a = a + 1;
    }
  return (0);
}
