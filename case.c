/*
** case_t.c for 103architect in /home/VEYSSI_B/rendu/103architect
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Nov 30 14:12:06 2015 Baptiste veyssiere
<<<<<<< HEAD
** Last update Mon Nov 30 18:25:26 2015 Baptiste veyssiere
=======
** Last update Mon Nov 30 16:58:37 2015 Baptiste veyssiere
>>>>>>> 0e0be9e27d650587c3d0e8b87a49e7f744c0bcb2
*/

#include <stdio.h>
#include <math.h>
#include "architech.h"

void	case_t(double x, double y, double Tx, double Ty, t_matrix *mat)
{
  printf("%.3g %.3g\n", mat->x, mat->y);
  printf("Translation by the vector (%.3g, %.3g)\n", Tx, Ty);
  mat->tab[0][0] += 1;
  mat->tab[0][1] += 0;
  mat->tab[0][2] += Tx;
  mat->tab[1][0] += 0;
  mat->tab[1][1] += 1;
  mat->tab[1][2] += Ty;
  mat->x = Tx + mat->x;
  mat->y = Ty + mat->y;
}

void    case_h(double x, double y, double Tx, double Ty, t_matrix *mat)
{
  printf("%.3g %.3g\n",mat->x, mat->y);
  printf("Homothety by the ratios %.3g and %.3g\n", Tx, Ty);
  mat->tab[0][0] += Tx;
  mat->tab[0][1] += 0.000;
  mat->tab[0][2] += 0.000;
  mat->tab[1][0] += 0.000;
  mat->tab[1][1] += Ty;
  mat->tab[1][2] += 1.000;
  mat->x = Tx * mat->x;
  mat->y = Ty * mat->y;
}

void    case_r(double x, double y, double A, double buffer, t_matrix *mat)
{
  double	a = cos((M_PI * A) / 180);
  double	b = -sin((M_PI * A) / 180);
  double	c = sin((M_PI * A) / 180);
  double	d = cos((M_PI * A) / 180);

  printf("%.3g %.3g\n", mat->x, mat->y);
  if (a < 0.001 && a > 0.000)
    a = 0;
  if (b < 0.001 && b > 0.000)
    b = 0;
  if (c < 0.001 && c > 0.000)
    c = 0;
  if (d < 0.001 && d > 0.000)
    d = 0;
  printf("Rotation at a %.3g degree angle\n", A);
  mat->tab[0][0] += a;
  mat->tab[0][1] += b;
  mat->tab[0][2] += 0.000;
  mat->tab[1][0] += c;
  mat->tab[1][1] += d;
  mat->tab[1][2] += 0.000;
  mat->x = a * mat->x + b * mat->y;
  mat->y = c * mat->x + d * mat->y;
}

void    case_s(double x, double y, double A, double buffer, t_matrix *mat)
{
  double	a = cos(2 * (M_PI * A) / 180);
  double	b = sin(2 * (M_PI * A) / 180);
  double	c = sin(2 * (M_PI * A) / 180);
  double	d = -cos(2 * (M_PI * A) / 180);

  printf("%.3g %.3g\n", mat->x, mat->y);
  if (a < 0.001 && a > 0.000)
    a = 0;
  if (b < 0.001 && b > 0.000)
    b = 0;
  if (c < 0.001 && c > 0.000)
    c = 0;
  if (d < 0.001 && d > 0.000)
    d = 0;
  printf("Symmetry about an axis inclined with an angle of %.3g degrees\n", A);
  mat->tab[0][0] += a;
  mat->tab[0][1] += b;
  mat->tab[0][2] += 0.000;
  mat->tab[1][0] += c;
  mat->tab[1][1] += d;
  mat->tab[1][2] += 0.000;
  mat->x = a * mat->x + b * mat->y;
  mat->y = c * mat->x + d * mat->y;
}
