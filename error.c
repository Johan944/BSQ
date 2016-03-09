/*
** error.c for  in /home/ganem-_j/rendu/CPE_2015_BSQ
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Fri Dec 18 11:59:04 2015 johan ganem--brunet
** Last update Mon Dec 21 20:43:31 2015 johan ganem--brunet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "bsq.h"

void	errors(struct stat *buf, int fd, char *buffer, int ac)
{
  if (ac < 2)
    my_puterr("Number of arguments invalid.");
  else if (fd > 3)
    my_puterr("The file doesn't exist.");
  else if (buffer == NULL || buf == NULL)
    my_puterr("Malloc failed.");
  else
    my_puterr("Structure 'stat' failed.");
  my_putchar('\n');
  my_puterr("\nFor more information : ./bsq -help\n");
  exit(-1);
}

int	check_end(t_map map, int idx2, int idx)
{
  if (map.buffer[idx2 + 1] == 0)
    {
      my_puterr("Invalid map.\n");
      my_puterr("For more information : ./bsq -help\n");
      exit(-1);
    }
  while (map.buffer[idx2] != 0)
    {
      if (map.buffer[idx2] == '\n' && map.buffer[idx2 + 1] == '\n')
	{
	  my_puterr("Invalid map.\n");
	  my_puterr("For more information : ./bsq -help\n");
	  exit(-1);
	}
      else if (map.buffer[idx2] != '.'
	       && map.buffer[idx2] != 'o' && map.buffer[idx2] != '\n')
	{
	  my_puterr("The map contains invalid characters.\n");
	  my_puterr("For more information : ./bsq -help\n");
	  exit(-1);
	}
      idx2 += 1;
    }
  if (idx == 3)
    disp_map(map.buffer);
}

int	first_line(t_map map, int idx, int idx2)
{
  while (map.buffer[idx2] != '\n')
    {
      if (map.buffer[idx2] == 0)
	{
	  my_puterr("The file doesn't contain a map.\n");
	  my_puterr("For more information : ./bsq -help\n");
	  exit(-1);
	}
      if (map.buffer[idx2] < 48 || map.buffer[idx2] > 57)
	{
	  my_puterr("The first line must contain a number.\n");
	  my_puterr("For more information : ./bsq -help\n");
	  exit(-1);
	}
      idx2 += 1;
    }
  if (map.buffer[idx2] == 0)
    {
      my_puterr("The file contains only 1 line");
      my_puterr("For more information : ./bsq -help\n");
      exit(-1);
    }
  check_end(map, idx2, idx);
}

int		malloc_array(t_map map, t_size size, t_bonus bonus)
{
  int		i;
  t_vars	vars;

  i = 0;
  if ((map.array = malloc(sizeof(int *) * size.lines)) == NULL)
    {
      my_puterr("Malloc failed");
      my_puterr("For more information : ./bsq -help\n");
      exit(-1);
    }
  while (i < size.lines)
    {
      if ((map.array[i++] = malloc(sizeof(int *) * size.cols)) == NULL)
	{
	  my_puterr("Malloc failed");
	  my_puterr("For more information : ./bsq -help\n");
	  exit(-1);
	}
    }
  init_array(map, size, bonus, vars);
  free(map.array);
}
