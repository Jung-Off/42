/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:24:00 by jji               #+#    #+#             */
/*   Updated: 2021/05/18 12:24:01 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_bool	hit_plane(t_fig *lst, t_ray *r, t_hit_record *rec)
{
	double	denominator;
	double	nom;
	double	t;

	denominator = vdot(r->dir, lst->fig.pl.n);
	nom = vdot(vsubstract(lst->fig.pl.p, r->origin), lst->fig.pl.n);
	if (!denominator)
		return (FALSE);
	t = nom / denominator;
	if (t < rec->t_min || t > rec->t_max)
		return (FALSE);
	rec->t = t;
	rec->p = ray_at(r, t);
	rec->normal = lst->fig.pl.n;
	rec->albedo = lst->albedo;
	set_face_normal(r, rec);
	return (TRUE);
}
