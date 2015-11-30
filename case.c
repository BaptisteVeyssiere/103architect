/*
** case_t.c for 103architect in /home/VEYSSI_B/rendu/103architect
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Nov 30 14:12:06 2015 Baptiste veyssiere
** Last update Mon Nov 30 15:04:09 2015 Baptiste veyssiere
*/

#include <stdio.h>
#include <math.h>

double	acos(double);
double	asin(double);

void	case_t(double x, double y, double Tx, double Ty)
{
  printf("Translation by the vector (%.f, %.f)\n1.000       0.000     %.3f\n0.000       1.000     %.3f\n0.000       0.000     1.000\n(%.f,%.f) => (%.f,%.f)\n", Tx, Ty, Tx, Ty, x, y, Tx + x, Ty + y);
}

void    case_h(double x, double y, double Tx, double Ty)
{
  printf("Homothety by the ratios %.f and %.f\n%.3f      0.000     0.000\n0.000       %.3f     0.000\n0.000       0.000     1.000\n(%.f,%.f) => (%.f,%.f)\n", Tx, Ty, Tx, Ty, x, y, Tx * x, Ty * y);
}

void    case_r(double x, double y, double A, double buffer)
{
  double	a = acos(A);
  double	b = -asin(A);
  double	c = asin(A);
  double	d = acos(A);
  printf("Rotation at a %.f degree angle\n%.3f       %.3f     0.000\n%.3f       %.3f     0.000\n0.000       0.000     1.000\n(%.f,%.f) => (%.f,%.f)\n", x, y, a, b, c, d, x, y, a * x + b * y, c * x + d * y);
}

void    case_s(double x, double y, double A, double buffer)
{
  double	a = acos(2 * A);
  double	b = asin(2 * A);
  double	c = asin(2 * A);
  double	d = -acos(2 * A);
  printf("Symmetry about an axis inclined with an angle of %.f degrees\n%3f       %3f     0.000\n%3f       %3f     0.000\n0.000       0.000     1.000\n(%.f,%.f) => (%.f,%.f)\n", x, y, a, b, c, d, x, y, a * x + b * y);
}
