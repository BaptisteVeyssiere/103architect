/*
** error.c for 103architect in /home/scutar_n/rendu/103architect
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Wed Dec  2 14:39:48 2015 nathan scutari
** Last update Wed Dec  2 15:29:03 2015 nathan scutari
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      i++;
    }
  return (i);
}

void	put_error(char *str, int output)
{
  write(2, str, my_strlen(str));
  exit(output);
}
