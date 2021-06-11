/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:19:15 by jji               #+#    #+#             */
/*   Updated: 2021/06/10 20:57:10 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/just_3.h"

int		max_3(t_link *a)
{
	int max;

	max = a->num;
	if (max < a->next->num)
		max = a->next->num;
	if (max < a->next->next->num)
		max = a->next->next->num;
	return (max);
}

int		min_3(t_link *a)
{
	int min;

	min = a->num;
	if (min > a->next->num)
		min = a->next->num;
	if (min > a->next->next->num)
		min = a->next->next->num;
	return (min);
}

void	first_3(t_link **a)
{
	swap_a(*a);
	rrotate_a(a);
}

void	num3_set(t_link **a)
{
	int max;
	int min;

	max = max_3(*a);
	min = min_3(*a);
	if (max == ((*a)->next->num))
	{
		if (min == (*a)->num)
		{
			rotate_a(a);
			swap_a(*a);
		}
		rrotate_a(a);
	}
	if (min == (*a)->next->num)
	{
		if (max == (*a)->num)
			rotate_a(a);
		else
			swap_a(*a);
	}
	if (max == (*a)->num)
		first_3(a);
}
