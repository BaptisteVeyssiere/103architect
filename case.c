/*
** case.c for 103architect in /home/scutar_n/rendu/103architect
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Wed Dec  2 16:04:37 2015 nathan scutari
** Last update Thu Dec 10 15:06:05 2015 nathan scutari
*/

#include <stdio.h>
#include <math.h>
#include "architech.h"

void	case_t(double x, double y, double Tx, double Ty, t_matrix *mat, int mode)
{
  t_matrix	mat2;
  t_matrix	mat3;

  printf("Translation by the vector (%.3g, %.3g)\n", Tx, Ty);
  mat2.tab[0][0] = 1;
  mat2.tab[0][1] = 0;
  mat2.tab[0][2] = Tx;
  mat2.tab[1][0] = 0;
  mat2.tab[1][1] = 1;
  mat2.tab[1][2] = Ty;
  mat2.tab[2][0] = 0;
  mat2.tab[2][1] = 0;
  mat2.tab[2][2] = 1;
  if (mode == 0)
    {
      mat3.tab[0][0] = mat->tab[0][0];
      mat3.tab[0][1] = mat->tab[0][1];
      mat3.tab[0][2] = mat->tab[0][2];
      mat3.tab[1][0] = mat->tab[1][0];
      mat3.tab[1][1] = mat->tab[1][1];
      mat3.tab[1][2] = mat->tab[1][2];
      mat3.tab[2][0] = mat->tab[2][0];
      mat3.tab[2][1] = mat->tab[2][1];
      mat3.tab[2][2] = mat->tab[2][2];
      mat->tab[0][0] = mat3.tab[0][0] * mat2.tab[0][0] + mat3.tab[1][0] * mat2.tab[0][1] + mat3.tab[2][0] * mat2.tab[0][2];
      mat->tab[0][1] = mat3.tab[0][1] * mat2.tab[0][0] + mat3.tab[1][1] * mat2.tab[0][1] + mat3.tab[2][1] * mat2.tab[0][2];
      mat->tab[0][2] = mat3.tab[0][2] * mat2.tab[0][0] + mat3.tab[1][2] * mat2.tab[0][1] + mat3.tab[2][2] * mat2.tab[0][2];
      mat->tab[1][0] = mat3.tab[0][0] * mat2.tab[1][0] + mat3.tab[1][0] * mat2.tab[1][1] + mat3.tab[2][0] * mat2.tab[1][2];
      mat->tab[1][1] = mat3.tab[0][1] * mat2.tab[1][0] + mat3.tab[1][1] * mat2.tab[1][1] + mat3.tab[2][1] * mat2.tab[1][2];
      mat->tab[1][2] = mat3.tab[0][2] * mat2.tab[1][0] + mat3.tab[1][2] * mat2.tab[1][1] + mat3.tab[2][2] * mat2.tab[1][2];
      mat->tab[2][0] = mat3.tab[0][0] * mat2.tab[2][0] + mat3.tab[1][0] * mat2.tab[2][1] + mat3.tab[2][0] * mat2.tab[2][2];
      mat->tab[2][1] = mat3.tab[0][1] * mat2.tab[2][0] + mat3.tab[1][1] * mat2.tab[2][1] + mat3.tab[2][1] * mat2.tab[2][2];
      mat->tab[2][2] = mat3.tab[0][2] * mat2.tab[2][0] + mat3.tab[1][2] * mat2.tab[2][1] + mat3.tab[2][2] * mat2.tab[2][2];
    }
  else
    {
      mat->tab[0][0] = mat2.tab[0][0];
      mat->tab[0][1] = mat2.tab[0][1];
      mat->tab[0][2] = mat2.tab[0][2];
      mat->tab[1][0] = mat2.tab[1][0];
      mat->tab[1][1] = mat2.tab[1][1];
      mat->tab[1][2] = mat2.tab[1][2];
      mat->tab[2][0] = mat2.tab[2][0];
      mat->tab[2][1] = mat2.tab[2][1];
      mat->tab[2][2] = mat2.tab[2][2];
    }
  mat->x = Tx + mat->x;
  mat->y = Ty + mat->y;
}

void    case_h(double x, double y, double Tx, double Ty, t_matrix *mat, int mode)
{
  t_matrix      mat2;
  t_matrix      mat3;

  printf("Homothety by the ratios %.3g and %.3g\n", Tx, Ty);
  mat2.tab[0][0] = Tx;
  mat2.tab[0][1] = 0.000;
  mat2.tab[0][2] = 0.000;
  mat2.tab[1][0] = 0.000;
  mat2.tab[1][1] = Ty;
  mat2.tab[1][2] = 0.000;
  mat2.tab[2][0] = 0;
  mat2.tab[2][1] = 0;
  mat2.tab[2][2] = 1;
  if (mode == 0)
    {
      mat3.tab[0][0] = mat->tab[0][0];
      mat3.tab[0][1] = mat->tab[0][1];
      mat3.tab[0][2] = mat->tab[0][2];
      mat3.tab[1][0] = mat->tab[1][0];
      mat3.tab[1][1] = mat->tab[1][1];
      mat3.tab[1][2] = mat->tab[1][2];
      mat3.tab[2][0] = mat->tab[2][0];
      mat3.tab[2][1] = mat->tab[2][1];
      mat3.tab[2][2] = mat->tab[2][2];
      mat->tab[0][0] = mat3.tab[0][0] * mat2.tab[0][0] + mat3.tab[1][0] * mat2.tab[0][1] + mat3.tab[2][0] * mat2.tab[0][2];
      mat->tab[0][1] = mat3.tab[0][1] * mat2.tab[0][0] + mat3.tab[1][1] * mat2.tab[0][1] + mat3.tab[2][1] * mat2.tab[0][2];
      mat->tab[0][2] = mat3.tab[0][2] * mat2.tab[0][0] + mat3.tab[1][2] * mat2.tab[0][1] + mat3.tab[2][2] * mat2.tab[0][2];
      mat->tab[1][0] = mat3.tab[0][0] * mat2.tab[1][0] + mat3.tab[1][0] * mat2.tab[1][1] + mat3.tab[2][0] * mat2.tab[1][2];
      mat->tab[1][1] = mat3.tab[0][1] * mat2.tab[1][0] + mat3.tab[1][1] * mat2.tab[1][1] + mat3.tab[2][1] * mat2.tab[1][2];
      mat->tab[1][2] = mat3.tab[0][2] * mat2.tab[1][0] + mat3.tab[1][2] * mat2.tab[1][1] + mat3.tab[2][2] * mat2.tab[1][2];
      mat->tab[2][0] = mat3.tab[0][0] * mat2.tab[2][0] + mat3.tab[1][0] * mat2.tab[2][1] + mat3.tab[2][0] * mat2.tab[2][2];
      mat->tab[2][1] = mat3.tab[0][1] * mat2.tab[2][0] + mat3.tab[1][1] * mat2.tab[2][1] + mat3.tab[2][1] * mat2.tab[2][2];
      mat->tab[2][2] = mat3.tab[0][2] * mat2.tab[2][0] + mat3.tab[1][2] * mat2.tab[2][1] + mat3.tab[2][2] * mat2.tab[2][2];
    }
  else
    {
      mat->tab[0][0] = mat2.tab[0][0];
      mat->tab[0][1] = mat2.tab[0][1];
      mat->tab[0][2] = mat2.tab[0][2];
      mat->tab[1][0] = mat2.tab[1][0];
      mat->tab[1][1] = mat2.tab[1][1];
      mat->tab[1][2] = mat2.tab[1][2];
      mat->tab[2][0] = mat2.tab[2][0];
      mat->tab[2][1] = mat2.tab[2][1];
      mat->tab[2][2] = mat2.tab[2][2];
    }
  mat->x = Tx * mat->x;
  mat->y = Ty * mat->y;
}

void    case_r(double x, double y, double A, double buffer, t_matrix *mat, int mode)
{
  t_matrix      mat2;
  t_matrix      mat3;
  double	x_copy;

  double	a = cos((M_PI * A) / 180);
  double	b = -sin((M_PI * A) / 180);
  double	c = sin((M_PI * A) / 180);
  double	d = cos((M_PI * A) / 180);

  if (a < 0.001 && a > 0.000)
    a = 0;
  if (b < 0.001 && b > 0.000)
    b = 0;
  if (c < 0.001 && c > 0.000)
    c = 0;
  if (d < 0.001 && d > 0.000)
    d = 0;
  printf("Rotation at a %.3g degree angle\n", A);
  mat2.tab[0][0] = a;
  mat2.tab[0][1] = b;
  mat2.tab[0][2] = 0.000;
  mat2.tab[1][0] = c;
  mat2.tab[1][1] = d;
  mat2.tab[1][2] = 0.000;
  mat2.tab[2][0] = 0;
  mat2.tab[2][1] = 0;
  mat2.tab[2][2] = 1;
  if (mode == 0)
    {
      mat3.tab[0][0] = mat->tab[0][0];
      mat3.tab[0][1] = mat->tab[0][1];
      mat3.tab[0][2] = mat->tab[0][2];
      mat3.tab[1][0] = mat->tab[1][0];
      mat3.tab[1][1] = mat->tab[1][1];
      mat3.tab[1][2] = mat->tab[1][2];
      mat3.tab[2][0] = mat->tab[2][0];
      mat3.tab[2][1] = mat->tab[2][1];
      mat3.tab[2][2] = mat->tab[2][2];
      mat->tab[0][0] = mat3.tab[0][0] * mat2.tab[0][0] + mat3.tab[1][0] * mat2.tab[0][1] + mat3.tab[2][0] * mat2.tab[0][2];
      mat->tab[0][1] = mat3.tab[0][1] * mat2.tab[0][0] + mat3.tab[1][1] * mat2.tab[0][1] + mat3.tab[2][1] * mat2.tab[0][2];
      mat->tab[0][2] = mat3.tab[0][2] * mat2.tab[0][0] + mat3.tab[1][2] * mat2.tab[0][1] + mat3.tab[2][2] * mat2.tab[0][2];
      mat->tab[1][0] = mat3.tab[0][0] * mat2.tab[1][0] + mat3.tab[1][0] * mat2.tab[1][1] + mat3.tab[2][0] * mat2.tab[1][2];
      mat->tab[1][1] = mat3.tab[0][1] * mat2.tab[1][0] + mat3.tab[1][1] * mat2.tab[1][1] + mat3.tab[2][1] * mat2.tab[1][2];
      mat->tab[1][2] = mat3.tab[0][2] * mat2.tab[1][0] + mat3.tab[1][2] * mat2.tab[1][1] + mat3.tab[2][2] * mat2.tab[1][2];
      mat->tab[2][0] = mat3.tab[0][0] * mat2.tab[2][0] + mat3.tab[1][0] * mat2.tab[2][1] + mat3.tab[2][0] * mat2.tab[2][2];
      mat->tab[2][1] = mat3.tab[0][1] * mat2.tab[2][0] + mat3.tab[1][1] * mat2.tab[2][1] + mat3.tab[2][1] * mat2.tab[2][2];
      mat->tab[2][2] = mat3.tab[0][2] * mat2.tab[2][0] + mat3.tab[1][2] * mat2.tab[2][1] + mat3.tab[2][2] * mat2.tab[2][2];
    }
  else
    {
      mat->tab[0][0] = mat2.tab[0][0];
      mat->tab[0][1] = mat2.tab[0][1];
      mat->tab[0][2] = mat2.tab[0][2];
      mat->tab[1][0] = mat2.tab[1][0];
      mat->tab[1][1] = mat2.tab[1][1];
      mat->tab[1][2] = mat2.tab[1][2];
      mat->tab[2][0] = mat2.tab[2][0];
      mat->tab[2][1] = mat2.tab[2][1];
      mat->tab[2][2] = mat2.tab[2][2];
    }
  x_copy = mat->x;
  mat->x = a * mat->x + b * mat->y;
  mat->y = c * x_copy + d * mat->y;
}

void    case_s(double x, double y, double A, double buffer, t_matrix *mat, int mode)
{
  t_matrix      mat2;
  t_matrix      mat3;
  double	x_copy;

  double	a = cos(2 * (M_PI * A) / 180);
  double	b = sin(2 * (M_PI * A) / 180);
  double	c = sin(2 * (M_PI * A) / 180);
  double	d = -cos(2 * (M_PI * A) / 180);

  if (a < 0.001 && a > 0.000)
    a = 0;
  if (b < 0.001 && b > 0.000)
    b = 0;
  if (c < 0.001 && c > 0.000)
    c = 0;
  if (d < 0.001 && d > 0.000)
    d = 0;
  printf("Symmetry about an axis inclined with an angle of %.3g degrees\n", A);
  mat2.tab[0][0] = a;
  mat2.tab[0][1] = b;
  mat2.tab[0][2] = 0.000;
  mat2.tab[1][0] = c;
  mat2.tab[1][1] = d;
  mat2.tab[1][2] = 0.000;
  mat2.tab[2][0] = 0;
  mat2.tab[2][1] = 0;
  mat2.tab[2][2] = 1;
  if (mode == 0)
    {
      mat3.tab[0][0] = mat->tab[0][0];
      mat3.tab[0][1] = mat->tab[0][1];
      mat3.tab[0][2] = mat->tab[0][2];
      mat3.tab[1][0] = mat->tab[1][0];
      mat3.tab[1][1] = mat->tab[1][1];
      mat3.tab[1][2] = mat->tab[1][2];
      mat3.tab[2][0] = mat->tab[2][0];
      mat3.tab[2][1] = mat->tab[2][1];
      mat3.tab[2][2] = mat->tab[2][2];
      mat->tab[0][0] = mat3.tab[0][0] * mat2.tab[0][0] + mat3.tab[1][0] * mat2.tab[0][1] + mat3.tab[2][0] * mat2.tab[0][2];
      mat->tab[0][1] = mat3.tab[0][1] * mat2.tab[0][0] + mat3.tab[1][1] * mat2.tab[0][1] + mat3.tab[2][1] * mat2.tab[0][2];
      mat->tab[0][2] = mat3.tab[0][2] * mat2.tab[0][0] + mat3.tab[1][2] * mat2.tab[0][1] + mat3.tab[2][2] * mat2.tab[0][2];
      mat->tab[1][0] = mat3.tab[0][0] * mat2.tab[1][0] + mat3.tab[1][0] * mat2.tab[1][1] + mat3.tab[2][0] * mat2.tab[1][2];
      mat->tab[1][1] = mat3.tab[0][1] * mat2.tab[1][0] + mat3.tab[1][1] * mat2.tab[1][1] + mat3.tab[2][1] * mat2.tab[1][2];
      mat->tab[1][2] = mat3.tab[0][2] * mat2.tab[1][0] + mat3.tab[1][2] * mat2.tab[1][1] + mat3.tab[2][2] * mat2.tab[1][2];
      mat->tab[2][0] = mat3.tab[0][0] * mat2.tab[2][0] + mat3.tab[1][0] * mat2.tab[2][1] + mat3.tab[2][0] * mat2.tab[2][2];
      mat->tab[2][1] = mat3.tab[0][1] * mat2.tab[2][0] + mat3.tab[1][1] * mat2.tab[2][1] + mat3.tab[2][1] * mat2.tab[2][2];
      mat->tab[2][2] = mat3.tab[0][2] * mat2.tab[2][0] + mat3.tab[1][2] * mat2.tab[2][1] + mat3.tab[2][2] * mat2.tab[2][2];
    }
  else
    {
      mat->tab[0][0] = mat2.tab[0][0];
      mat->tab[0][1] = mat2.tab[0][1];
      mat->tab[0][2] = mat2.tab[0][2];
      mat->tab[1][0] = mat2.tab[1][0];
      mat->tab[1][1] = mat2.tab[1][1];
      mat->tab[1][2] = mat2.tab[1][2];
      mat->tab[2][0] = mat2.tab[2][0];
      mat->tab[2][1] = mat2.tab[2][1];
      mat->tab[2][2] = mat2.tab[2][2];
    }
  x_copy = mat->x;
  mat->x = a * mat->x + b * mat->y;
  mat->y = c * x_copy + d * mat->y;
}
