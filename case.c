/*
** case_t.c for 103architect in /home/VEYSSI_B/rendu/103architect
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Nov 30 14:12:06 2015 Baptiste veyssiere
** Last update Mon Nov 30 16:03:37 2015 Baptiste veyssiere
*/

#include <stdio.h>
#include <math.h>

double	acos(double);
double	asin(double);

void	case_t(double x, double y, double Tx, double Ty)
{
  printf("Translation by the vector (%.3g, %.3g)\n1.000       0.000     %.3f\n0.000       1.000     %.3f\n0.000       0.000     1.000\n(%.3g,%.3g) => (%.3g,%.3g)\n", Tx, Ty, Tx, Ty, x, y, Tx + x, Ty + y);
}

void    case_h(double x, double y, double Tx, double Ty)
{
  printf("Homothety by the ratios %.3g and %.3g\n%.3f    0.000      0.000\n0.000     %.3f      0.000\n0.000     0.000      1.000\n(%.3g,%.3g) => (%.3g,%.3g)\n", Tx, Ty, Tx, Ty, x, y, Tx * x, Ty * y);
}

void    case_r(double x, double y, double A, double buffer)
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
  printf("Rotation at a %.3g degree angle\n%.3f       %.3f     0.000\n%.3f       %.3f     0.000\n0.000       0.000     1.000\n(%.3g,%.3g) => (%.3g,%.3g)\n", A, a, b, c, d, x, y, (a * x + b * y), (c * x + d * y));
}

void    case_s(double x, double y, double A, double buffer)
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
  printf("Symmetry about an axis inclined with an angle of %.3g degrees\n%.3f       %.3f     0.000\n%.3f       %.3f     0.000\n0.000       0.000     1.000\n(%.3g,%.3g) => (%.3g,%.3g)\n", A, a, b, c, d, x, y, (a * x + b * y), (c * x + d * y));
}
