/*
** architech.h for 103architect in /home/scutar_n/rendu/103architect
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon Nov 30 15:07:34 2015 nathan scutari
** Last update Thu Dec  3 15:58:24 2015 Baptiste veyssiere
*/

#ifndef ARCHITECT_H_
# define ARCHITECT_H_

typedef struct s_file
{
  char	option;
  float	nbr1;
  float	nbr2;
  struct s_file *next;
}		t_file;

typedef struct s_matrix
{
  double	tab[3][3];
  double	x;
  double	y;
} t_matrix;

void case_t(double, double, double, double, t_matrix*);
void case_h(double, double, double, double, t_matrix*);
void case_r(double, double, double, double, t_matrix*);
void case_s(double, double, double, double, t_matrix*);

#endif /* !ARCHITECT_H_ */
