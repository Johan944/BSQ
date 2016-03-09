/*
** main.c for  in /home/ganem-_j/rendu/CPE_2015_BSQ
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Thu Dec 17 19:54:15 2015 johan ganem--brunet
** Last update Mon Dec 21 22:59:02 2015 johan ganem--brunet
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bsq.h"

int	detect_bonus(char **flag, int ac)
{
  if (ac >= 3)
    {
      if (my_strcmp(flag[2], "-color") == 0)
	return (1);
      else if (my_strcmp(flag[2], "-text") == 0)
	return (2);
      else if (my_strcmp(flag[2], "-cat") == 0)
	return (3);
      my_puterr("Invalid option.\nFor more information : ./bsq -help\n");
      exit(-1);
    }
  return (0);
}

int		main(int ac, char **av)
{
  struct stat	*buf;
  t_size	size;
  t_map		map;
  t_bonus	bonus;
  int		fd;
  char		*firstline;

  if (ac != 1 && my_strcmp(av[1], "-help") == 0)
    {
      disp_help();
      return (1);
    }
  if ((ac < 2) || ((buf = malloc(sizeof(*buf))) == NULL)
      || (stat(av[1], buf) == -1)
      || ((map.buffer = malloc(sizeof(char *)*buf->st_size)) == NULL)
      || ((fd = open(av[1], O_RDONLY))) == -1)
    errors(buf, fd, map.buffer, ac);
  bonus.idx = detect_bonus(av, ac);
  fill_buffer(map, fd, buf->st_size);
  first_line(map, bonus.idx, 0);
  size.lines = nbr_lines(map.buffer, 0, 0, firstline);
  size.cols = nbr_cols(map.buffer);
  malloc_array(map, size, bonus);
  free(map.buffer);
  free(buf);
}
