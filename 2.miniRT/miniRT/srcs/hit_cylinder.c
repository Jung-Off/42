/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:23:28 by jji               #+#    #+#             */
/*   Updated: 2021/05/18 12:23:29 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_p3	get_cy_normal(t_p3 pos, t_fig *lst)
{
	t_p3	tmp;
	t_p3	normal;

	tmp = vsubstract(pos, lst->fig.cy.c);
	normal = vunit(vsubstract(tmp,
				vscalarmul(lst->fig.cy.n, vdot(lst->fig.cy.n, tmp))));
	return (normal);
}

int		cy_boundary(t_fig *lst, t_ray *r, t_cy_data var)
{
	double	len;

	var.p = ray_at(r, var.t);
	len = sqrt(pow(lst->fig.cy.r, 2.0) + pow(lst->fig.cy.height, 2.0));
	if (ft_vec_dist(lst->fig.cy.c, var.p) > len)
		return (0);
	return (1);
}

int		intersect_cylinder(t_fig *lst, t_ray *r, t_hit_record *rec, int flag)
{
	t_cy_data	var;

	var.r2 = lst->fig.cy.r * lst->fig.cy.r;
	var.top = vsubstract(lst->fig.cy.c,
			vscalarmul(lst->fig.cy.n, lst->fig.cy.height));
	var.bot = vadd(lst->fig.cy.c,
			vscalarmul(lst->fig.cy.n, lst->fig.cy.height));
	var.hc = vsubstract(var.top, var.bot);
	var.h = vunit(var.hc);
	var.w = vsubstract(r->origin, var.bot);
	var.v = r->dir;
	if (!(var.t = cy_calc(var, rec, flag)))
		return (0);
	if (!cy_boundary(lst, r, var))
		return (0);
	rec->t = var.t;
	rec->p = ray_at(r, var.t);
	rec->normal = get_cy_normal(rec->p, lst);
	rec->albedo = lst->albedo;
	return (1);
}

t_bool	hit_cylinder(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	int		i;
	int		flag;
	t_bool	res;

	i = 2;
	flag = 1;
	res = FALSE;
	while (i--)
	{
		if ((res = intersect_cylinder(lst, r, rec, flag)))
			i = 0;
		flag = 0;
	}
	return (res);
}
