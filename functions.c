/*
** functions.c for  in /home/ganem-_j/rendu/CPE_2015_BSQ
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Tue Dec 15 11:54:04 2015 johan ganem--brunet
** Last update Sun Dec 20 22:35:32 2015 johan ganem--brunet
*/

#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i += 1;
    }
}

void	my_put_nbr(int nb)
{
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0');
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i])
    i += 1;
  return (s1[i] - s2[i]);
}

int	my_atoi(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  j = j * 10;
	  j = j + str[i] - '0';
	}
      i = i + 1;
    }
  return (j);
}
