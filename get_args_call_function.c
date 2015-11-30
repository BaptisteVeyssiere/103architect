/*
** get_args_call_function.c for 103architect in /home/scutar_n/rendu/103architect
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon Nov 30 14:12:19 2015 nathan scutari
** Last update Mon Nov 30 17:22:38 2015 nathan scutari
*/

#include <stdio.h>
#include <stdlib.h>
#include "architech.h"
#include <math.h>

void	nbrcpy(char *st)
{
  int	i;

  i = 0;
  if (st[i] == '-')
    i++;
  if (st[i] == 0)
    exit(84);
  while (st[i] != 0)
    {
      if (st[i] < '0' || st[i] > '9')
	exit(84);
      i++;
    }
}


int		my_put_in_list(t_file **list, char *option, char *nbr1, char *nbr2, int i)
{
  t_file	*elem;

  elem = malloc(sizeof(*elem));
  elem->next = *list;
  *list = elem;
  if (option[0] == '-' && (option[1] == 't' || option[1] == 'h' || option[1] == 'r' || option[1] == 's') && option[2] == 0)
    elem->option = option[1];
  else
    exit(84);
  if (elem->option == 't' || elem->option == 'h')
    {
      nbrcpy(nbr1);
      elem->nbr1 = atof(nbr1);
      nbrcpy(nbr2);
      elem->nbr2 = atof(nbr2);
      i -= 3;
    }
  if (elem->option == 'r' || elem->option == 's')
    {
      elem->nbr1 = atof(nbr1);
      i -= 3;
    }
  return (i);
}
void		get_args_call_function(int ac, char **av)
{
  t_file	*list;
  int		i;
  int		j;
  t_matrix	matrix;
  char		f_list[] = "thrs";
  void	(*caseoid[])(double, double, double, double, t_matrix*) =
    {
      case_t,
      case_h,
      case_r,
      case_s,
      0
    };
  i = ac - 1;
  list = NULL;
  matrix.x = atof(av[1]);
  matrix.y = atof(av[2]);
  matrix.tab[0][0] = 0;
  matrix.tab[0][1] = 0;
  matrix.tab[0][2] = 0;
  matrix.tab[1][0] = 0;
  matrix.tab[1][1] = 0;
  matrix.tab[1][2] = 0;
  while (av[i][0] != '-' || av[i][1] != 't' && av[i][1] != 'h' && av[i][1] != 'r' && av[i][1] != 's')
    i--;
  while (i > 2)
    {
      my_put_in_list(&list, av[i], av[i + 1], av[i + 2], i);
      i--;
      while (av[i][1] != 'r' && av[i][1] != 's' && av[i][1] != 't' && av[i][1] != 'h' && i > 0)
	i--;
    }
  while (list != NULL)
    {
      j = 0;
      while (list->option != f_list[j])
	j++;
      caseoid[j](atof(av[1]), atof(av[2]), list->nbr1, list->nbr2, &matrix);
      list = list->next;
    }
  printf("%.3f\t%.3f\t%.3f\n%.3f\t%.3f\t%.3f\n0.000\t0.000\t1.000\n", matrix.tab[0][0], matrix.tab[0][1], matrix.tab[0][2], matrix.tab[1][0], matrix.tab[1][1], matrix.tab[1][2]);
  printf("(%.3g,%.3g) => (%.3g,%.3g)\n", atof(av[1]), atof(av[2]), matrix.x, matrix.y);
}

int	main(int ac, char **av)
{
  get_args_call_function(ac, av);
}
