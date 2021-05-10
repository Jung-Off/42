#include "../includes/shadow.h"

t_bool in_shadow(t_fig *lst, t_ray light_ray, double light_len)
{
    t_hit_record rec;
    rec.tmin = 0;
    rec.tmax = light_len;
    if(hit(lst, &light_ray, &rec))
        return(TRUE);
    return (FALSE);
}