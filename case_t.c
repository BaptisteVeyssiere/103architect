/*
** case_t.c for 103architect in /home/VEYSSI_B/rendu/103architect
**
** Made by Baptiste veyssiere
** Login   <VEYSSI_B@epitech.net>
**
** Started on  Mon Nov 30 14:12:06 2015 Baptiste veyssiere
** Last update Mon Nov 30 14:38:52 2015 Baptiste veyssiere
*/

#include <stdio.h>
#include <math.h>

void	case_t(float x, float y, float Tx, float Ty)
{
  printf("Translation by the vector (%f, %f)\n1.OOO    0.000    %f\n0.000    1.000    %f\n0.000    0.000    1.000\n(%f,%f) => (%f,%f)\n", x, y, Tx, Ty, x, y, Tx + x, Ty + y);
}

void    case_h(float x, float y, float Tx, float Ty)
{
  printf("Homothety by the ratios %f and %f\n%f    0.000    0.000\n0.000    %f    0.000\n0.000    0.000    1.000\n(%f,%f) => (%f,%f)\n", x, y, Tx, Ty, x, y, Tx * x, Ty * y);
}

void    case_r(float x, float y, float A)
{
  float	a = acoshf(A);
  float	b = -asinhf(A);
  float	c = asinhf(A);
  float	d = acoshf(A);
  printf("Rotation at a %f degree angle\n%f    %f    0.000\n%f    %f    0.000\n0.000    0.000    1.000\n(%f,%f) => (%f,%f)\n", x, y, a, b, c, d, x, y, a * x + b * y, c * x + d * y);
}

void    case_s(float x, float y, float A)
{
  float	a = acoshf(2 * A);
  float	b = asinhf(2 * A);
  float	c = asinhf(2 * A);
  float	d = -acoshf(2 * A);
  printf("Symmetry about an axis inclined with an angle of %f degrees\n%f    %f    0.000\n%f    %f    0.000\n0.000    0.000    1.000\n(%f,%f) => (%f,%f)\n", x, y, a, b, c, d, x, y, a * x + b * y);
}
