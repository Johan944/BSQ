/*
** bsq.h for  in /home/ganem-_j/rendu/CPE_2015_BSQ
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Thu Dec 17 12:12:04 2015 johan ganem--brunet
** Last update Sun Dec 20 22:09:33 2015 johan ganem--brunet
*/

#ifndef BSQ_H_
# define BSQ_H_

typedef struct	s_size
{
  int	lines;
  int	cols;
  int	max;
  int	x;
  int	y;
  int	bigger;
  int	obstacles;
}		t_size;

typedef struct	s_map
{
  char	*buffer;
  int	**array;
}		t_map;

typedef struct	s_vars
{
  int	i;
  int	j;
  int	k;
  int	tmp1;
  int	tmp2;
}		t_vars;

typedef struct	s_bonus
{
  int	idx;
}		t_bonus;

#endif /* !BSQ_H_ */
