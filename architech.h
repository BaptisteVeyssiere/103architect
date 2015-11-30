/*
** architech.h for 103architect in /home/scutar_n/rendu/103architect
**
** Made by nathan scutari
** Login   <scutar_n@epitech.net>
**
** Started on  Mon Nov 30 15:07:34 2015 nathan scutari
** Last update Mon Nov 30 15:13:28 2015 nathan scutari
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

double case_t(double, double, double, double);
double case_h(double, double, double, double);
double case_r(double, double, double, double);
double case_s(double, double, double, double);

#endif /* !ARCHITECT_H_ */
