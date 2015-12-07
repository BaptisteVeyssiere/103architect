/*
** get_args_call_function.c for 103architect in /home/scutar_n/rendu/103architect
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon Nov 30 14:12:19 2015 nathan scutari
** Last update Mon Dec  7 14:18:52 2015 Baptiste veyssiere
*/

#include <stdio.h>
#include <stdlib.h>
#include "architech.h"
#include <math.h>

void            reverse_list(t_file **list)
{
  t_file        *tmp;
  t_file        *previous;
  t_file        *save;
  t_file        *list_b;

  tmp = *list;
  previous = NULL;
  while (tmp != NULL)
    {
      save = tmp->next;
      tmp->next = previous;
      previous = tmp;
      list_b = tmp;
      tmp = save;
    }
  *list = list_b;
}

int	is_nbr(char	charact)
{
  if (charact < '0' || charact > '9')
    return (0);
  return (1);
}

void	verify_number(char *str)
{
  int	i;
  int	j;
  int	point;

  point = 0;
  i = 0;
  j = 0;
  while (str[i] != 0)
    {
      if (str[i] == '-' && i == 0)
	i++;
      if (is_nbr(str[i]) == 0 && str[i] != 46)
	put_error("Syntax error\n", 84);
      if (str[i] == 46 && point > 0)
	put_error("Syntax error\n", 84);
      if (str[i] == 46 && point == 0)
	point = 1;
      if (str[i] == 46 && is_nbr(str[i + 1]) == 0)
	put_error("Syntax error\n", 84);
      i++;
    }
}

void	nbrcpy(char *st)
{
  int	i;

  i = 0;
  if (st[i] == '-')
    i++;
  if (st[i] == 0)
    put_error("Error : option is not a number\n", -1);
  while (st[i] != 0)
    {
      if (st[i] < '0' || st[i] > '9')
	put_error("Error : option is not a number\n", -1);
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
      verify_number(nbr1);
      verify_number(nbr2);
      nbrcpy(nbr1);
      elem->nbr1 = atof(nbr1);
      nbrcpy(nbr2);
      elem->nbr2 = atof(nbr2);
      i -= 3;
    }
  if (elem->option == 'r' || elem->option == 's')
    {
      verify_number(nbr1);
      elem->nbr1 = atof(nbr1);
      i -= 3;
    }
  return (i);
}
void		get_args_call_function(int ac, char **av)
{
  t_file	*list;
  int		i;
  int		option;
  int		j;
  t_matrix	matrix;
  char		f_list[] = "thrs";
  void	(*caseoid[])(double, double, double, double, t_matrix*, int) =
    {
      case_t,
      case_h,
      case_r,
      case_s,
      0
    };
  i = 3;
  list = NULL;
  if (ac < 5)
    put_error("Error : invalid number of arguments\n", -1);
  verify_number(av[1]);
  verify_number(av[2]);
  matrix.x = atof(av[1]);
  matrix.y = atof(av[2]);
  /*matrix.tab[0][0] = 1;
  matrix.tab[0][1] = 1;
  matrix.tab[0][2] = 1;
  matrix.tab[1][0] = 1;
  matrix.tab[1][1] = 1;
  matrix.tab[1][2] = 1;
  matrix.tab*/
  while (i < ac)
    {
      if (my_strlen(av[i]) == 2)
	{
	  if ((av[i][1] == 't' || av[i][1] == 'h') && ac >= i + 3)
	    {
	      my_put_in_list(&list, av[i], av[i + 1], av[i + 2], i);
	      i += 3;
	    }
	  else if ((av[i][1] == 'r' || av[i][1] == 's') && ac >= i + 2)
	    {
	      my_put_in_list(&list, av[i], av[i + 1], av[i + 2], i);
	      i += 2;
	    }
	  else
	    put_error("Error : bad options\n", -1);
	}
      else
	put_error("Error : bad options\n", -1);
    }
  reverse_list(&list);
  option = 1;
  while (list != NULL)
    {
      j = 0;
      while (list->option != f_list[j])
	j++;
      caseoid[j](atof(av[1]), atof(av[2]), list->nbr1, list->nbr2, &matrix, option);
      option = 0;
      list = list->next;
    }
  printf("%.2f\t%.2f\t%.2f\n%.2f\t%.2f\t%.2f\n0.00\t0.00\t1.00\n", matrix.tab[0][0], matrix.tab[0][1], matrix.tab[0][2], matrix.tab[1][0], matrix.tab[1][1], matrix.tab[1][2]);
  printf("(%.3g,%.3g) => (%.2f,%.2f)\n", atof(av[1]), atof(av[2]), matrix.x, matrix.y);
}

int	main(int ac, char **av)
{
  get_args_call_function(ac, av);
}
