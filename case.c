/*
** case_t.c for 103architect in /home/VEYSSI_B/rendu/103architect
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Nov 30 14:12:06 2015 Baptiste veyssiere
** Last update Mon Nov 30 16:58:37 2015 Baptiste veyssiere
*/

#include <stdio.h>
#include <math.h>
#include "architect.h"

double	acos(double);
double	asin(double);

void	case_t(double x, double y, double Tx, double Ty, t_matrix *mat)
{
  printf("Translation by the vector (%.3g, %.3g)\n", Tx, Ty);
  mat->tab[0][0] = 1.000;
  mat->tab[0][1] = 0.000;
  mat->tab[0][2] = Tx;
  mat->tab[1][0] = 0.000;
  mat->tab[1][1] = 1.000;
  mat->tab[1][2] = Ty;
  mat->x = Tx + x;
  mat->y = Ty + y;
}

void    case_h(double x, double y, double Tx, double Ty, t_matrix *mat)
{
  printf("Homothety by the ratios %.3g and %.3g\n", Tx, Ty);
  mat->tab[0][0] = Tx;
  mat->tab[0][1] = 0.000;
  mat->tab[0][2] = 0.000;
  mat->tab[1][0] = 0.000;
  mat->tab[1][1] = Ty;
  mat->tab[1][2] = 1.000;
  mat->x = Tx * x;
  mat->y = Ty * y;
}

void    case_r(double x, double y, double A, double buffer, t_matrix *mat)
{
  double	a = cos((M_PI * A) / 180);
  double	b = -sin((M_PI * A) / 180);
  double	c = sin((M_PI * A) / 180);
  double	d = cos((M_PI * A) / 180);
  if (a < 0.001)
    a = 0;
  if (b < 0.001)
    b = 0;
  if (c < 0.001)
    c = 0;
  if (d < 0.001)
    d = 0;
  printf("Rotation at a %.3g degree angle\n", A);
  mat->tab[0][0] = a;
  mat->tab[0][1] = b;
  mat->tab[0][2] = 0.000;
  mat->tab[1][0] = c;
  mat->tab[1][1] = d;
  mat->tab[1][2] = 0.000;
  mat->x = a * x + b * y;
  mat->y = c * x + d * y;
}

void    case_s(double x, double y, double A, double buffer, t_matrix *mat)
{
  double	a = cos(2 * (M_PI * A) / 180);
  double	b = sin(2 * (M_PI * A) / 180);
  double	c = sin(2 * (M_PI * A) / 180);
  double	d = -cos(2 * (M_PI * A) / 180);
  if (a < 0.001)
    a = 0;
  if (b < 0.001)
    b = 0;
  if (c < 0.001)
    c = 0;
  if (d < 0.001)
    d = 0;
  printf("Symmetry about an axis inclined with an angle of %.3g degrees\n", A);
  mat->tab[0][0] = a;
  mat->tab[0][1] = b;
  mat->tab[0][2] = 0.000;
  mat->tab[1][0] = c;
  mat->tab[1][1] = d;
  mat->tab[1][2] = 0.000;
  mat->x = a * x + b * y;
  mat->y = c * x + d * y;
}

void	main()
{
  case_t(1, 2, 2, 1);
}
