#ifndef _VECOPERATION_H_
# define _VECOPERATION_H_


#include "main.h"

t_p3	vdefine(double x, double y, double z);
t_p3	vadd(t_p3 a, t_p3 b);
t_p3	vsubstract(t_p3 a, t_p3 b);
double	vdot(t_p3 a, t_p3 b);
t_p3	vcross(t_p3 a, t_p3 b);



#endif