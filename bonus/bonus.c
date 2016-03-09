/*
** bonus.c for  in /home/ganem-_j/rendu/CPE_2015_BSQ
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Fri Dec 18 16:02:11 2015 johan ganem--brunet
** Last update Mon Dec 21 23:10:58 2015 johan ganem--brunet
*/

#include <stdlib.h>
#include "../bsq.h"

void	disp_color(t_size size, t_map map)
{
  size.y = 0;
  while (size.y != size.lines)
    {
      size.x = 0;
      while (size.x != size.cols)
	{
	  if (map.array[size.y][size.x] == -1)
	    write(1, "\033[1;31mx\033[0m", 12);
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

void	disp_text(t_size size, t_vars vars)
{
  my_putstr("Details of the map :\n\n");
  my_putstr("Width  : ");
  my_put_nbr(size.cols);
  my_putstr("\nHeight : ");
  my_put_nbr(size.lines);
  my_putstr("\nSize : ");
  my_put_nbr(size.cols * size.lines);
  my_putstr("\nObstacles : ");
  my_put_nbr(size.obstacles);
  my_putstr("\nFree space : ");
  my_put_nbr(size.cols * size.lines - size.obstacles);
  my_putstr("\n\n------------------------------\n\n");
  my_putstr("Details of the biggest square :");
  my_putstr("\n\nSize : ");
  my_put_nbr(size.bigger);
  my_putstr("\nArea : ");
  my_put_nbr(size.bigger * size.bigger);
  my_putstr(" (~");
  my_put_nbr((100 * size.bigger * size.bigger) / (size.cols * size.lines));
  my_putstr("%)");
  my_putstr("\nx : ");
  my_put_nbr(vars.tmp1 + size.bigger + 1);
  my_putstr("\ny : ");
  my_put_nbr(vars.tmp2 + size.bigger + 1);
  write(1, "\n", 1);
}

void	disp_help()
{
  my_putstr("-----------------------------------------------------------\n");
  my_putstr("                            HELP                           \n");
  my_putstr("-----------------------------------------------------------\n\n");
  my_putstr("To use this program, you must put at least two arguments :\n\n");
  my_putstr("1. ./bsq -> to execute\n\n");
  my_putstr("2. the name of the map\n\n");
  my_putstr("3. an option\n\n");
  my_putstr("-----------------------------------------------------------\n\n");
  my_putstr("List of options possible :\n\n");
  my_putstr("-color to display the biggest square in red\n\n");
  my_putstr("-text to display the statistics of the biggest square\n\n");
  my_putstr("-cat to display the map\n\n");
  my_putstr("\033[1;31mWARNING: You can't use two options at the same time\n");
  my_putstr("\033[0m\n");
  my_putstr("-----------------------------------------------------------\n\n");
  my_putstr("Details of the map :\n\n");
  my_putstr("1.The first line must contain the number of lines of the map\n");
  my_putstr("\n2.The map must contain only '.' or 'o'\n\n");
  my_putstr("-----------------------------------------------------------\n\n");
  my_putstr("Exemple :\n\n");
  my_putstr("For a map called 'map' :\n");
  my_putstr("5\noo....o\no.....o\n.......\no......\n..oo...\n");
  my_putstr("\n./bsq map -color\n");
  my_putstr("oo\033[1;31mxxxx\033[0mo\no.\033[1;31mxxxx\033[0mo\n");
  my_putstr("..\033[1;31mxxxx\033[0m.\no.\033[1;31mxxxx\033[0m.\n..oo...\n");
}

void	disp_map(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i - 1] != '\n')
    i += 1;
  while (buffer[i] != 0)
    {
      my_putchar(buffer[i]);
      i += 1;
    }
  exit(-1);
}

void	disp_final(t_bonus bonus, t_size size, t_vars vars, t_map map)
{
  if (bonus.idx == 1)
    disp_color(size, map);
  else if (bonus.idx == 2)
    disp_text(size, vars);
  else
    disp_normal(size, map);
}
