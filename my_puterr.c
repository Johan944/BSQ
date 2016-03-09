/*
** my_puterr.c for  in /home/ganem-_j/rendu/CPE_2015_BSQ
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Mon Dec 21 13:34:46 2015 johan ganem--brunet
** Last update Mon Dec 21 13:35:26 2015 johan ganem--brunet
*/

void	my_puterr(char *str)
{
  while (*str)
    write(2, str++, 1);
}
