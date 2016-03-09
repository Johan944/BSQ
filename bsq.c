/*
** main.c for  in /home/ganem-_j/rendu/CPE_2015_BSQ
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Tue Dec 15 09:37:29 2015 johan ganem--brunet
** Last update Mon Dec 21 20:36:01 2015 johan ganem--brunet
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "bsq.h"

int	find_square(t_size size, t_map map, t_vars vars)
{
  int	a;
  int	b;
  int	c;

  size.max = 0;
  a = map.array[vars.j - 1][vars.k];
  b = map.array[vars.j][vars.k - 1];
  c = map.array[vars.j - 1][vars.k - 1];
  if (a < b)
    b = a;
  if (b < c)
    c = b;
  return (c + 1);
}

int	check(t_map map, t_size size,
	      t_vars vars)
{
  if (map.buffer[vars.i] == 'o')
    return (0);
  else if (vars.k == 0 || vars.j == 0)
    return (1);
  else if (map.buffer[vars.i] == '.')
    return (find_square(size, map, vars));
}

void	detect(t_map map, t_size size,
	       t_vars vars, t_bonus bonus)
{
  while (map.array[size.x][size.y] != size.bigger)
    {
      if (size.y < size.cols)
	size.y += 1;
      else
	{
	  size.y = 0;
	  size.x += 1;
	}
    }
  vars.tmp1 = size.y - size.bigger;
  vars.tmp2 = size.x - size.bigger;
  while (size.y != vars.tmp1)
    {
      size.x = vars.tmp2 + size.bigger;
      while (size.x != vars.tmp2)
	{
	  map.array[size.x][size.y] = -1;
	  size.x -= 1;
	}
      size.y -= 1;
    }
  disp_final(bonus, size, vars, map);
}

int	disp_normal(t_size size, t_map map)
{
  size.y = 0;
  size.x = 0;
  while (size.y != size.lines)
    {
      size.x = 0;
      while (size.x != size.cols)
	{
	  if (map.array[size.y][size.x] == -1)
	    write(1, "x", 1);
	  else if (map.array[size.y][size.x] == 0)
	    write(1, "o", 1);
	  else
	    write(1, ".", 1);
	  size.x += 1;
	}
      write(1, "\n", 1);
      size.y += 1;
    }
}

int	init_array(t_map map, t_size size, t_bonus bonus, t_vars vars)
{
  vars.i = 0;
  vars.j = 0;
  size.bigger = 0;
  while (map.buffer[vars.i - 1] != '\n')
    vars.i += 1;
  while (vars.j != size.lines)
    {
      vars.k = 0;
      while (vars.k != size.cols)
	{
	  if (map.buffer[vars.i] == 'o')
	    size.obstacles += 1;
	  map.array[vars.j][vars.k] = check(map, size, vars);
	  if (map.array[vars.j][vars.k] > size.bigger)
	    size.bigger = map.array[vars.j][vars.k];
	  vars.k += 1;
	  vars.i += 1;
	}
      vars.i += 1;
      vars.j += 1;
    }
  size.x = 0;
  size.y = 0;
  detect(map, size, vars, bonus);
}
