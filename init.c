/*
** lines_cols.c for  in /home/ganem-_j/rendu/CPE_2015_BSQ
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Thu Dec 17 14:36:44 2015 johan ganem--brunet
** Last update Mon Dec 21 19:42:31 2015 johan ganem--brunet
*/

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

void	fill_buffer(t_map map, int fd, int size_buffer)
{
  int	i;
  int	k;

  k = 1;
  while (k != 0)
    {
      if ((k = read(fd, map.buffer, size_buffer)) == -1)
	{
	  my_puterr("Read failed\n");
	  exit(-1);
	}
    }
}

int	nbr_lines(char *buffer, int i, int nbr, char *firstline)
{
  if ((firstline = malloc(sizeof(*buffer))) == NULL)
    {
      my_puterr("Malloc failed\nFor more information : ./bsq -help\n");
      exit(-1);
    }
  while (buffer[i] != '\n')
    {
      firstline[i] = buffer[i];
      i += 1;
    }
  while (buffer[i] != 0)
    {
      if (buffer[i] == '\n')
	nbr += 1;
      i += 1;
    }
  if (nbr - 1 != my_atoi(firstline))
    {
      my_puterr("The number in the first line is false\n");
      my_puterr("For more information : ./bsq -help\n");
      exit (-1);
    }
  free(firstline);
  return (nbr - 1);
}

void	check_cols(char *buffer, int nbr)
{
  int	i;
  int	j;

  i = 0;
  while (buffer[i - 1] != '\n')
    i += 1;
  while (buffer[i] != 0)
    {
      j = 0;
      while (buffer[i] != '\n')
	{
	  j += 1;
	  i += 1;
	}
      if (j != nbr)
	{
	  my_puterr("The lines must have the same number of columns\n");
	  my_puterr("For more information : ./bsq -help\n");
	  exit(-1);
	}
      i += 1;
    }
}

int	nbr_cols(char *buffer)
{
  int	i;
  int	nbr;

  i = 0;
  nbr = 0;
  while (buffer[i] != '\n')
    i += 1;
  i += 1;
  while (buffer[i] != '\n')
    {
      nbr += 1;
      i += 1;
    }
  check_cols(buffer, nbr);
  return (nbr);
}
