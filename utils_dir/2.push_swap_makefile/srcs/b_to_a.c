/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:17:58 by jji               #+#    #+#             */
/*   Updated: 2021/06/10 20:48:11 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_to_a.h"

static void	before_push(t_link **b, int rotate)
{
	while (rotate--)
		rrotate_b(b);
}

static void	set_2(t_link **b)
{
	if ((*b)->num < (*b)->next->num)
		swap_b(*b);
}

static int	except_case(t_link **a, t_link **b, int len)
{
	if (len == 1)
	{
		push_a(a, b);
		return (1);
	}
	else if (len == 2)
	{
		set_2(b);
		push_a(a, b);
		push_a(a, b);
		return (1);
	}
	return (0);
}

void		b_to_a(t_link **a, t_link **b, int len)
{
	int pivot;
	int rotate;
	int push;

	rotate = 0;
	push = 0;
	if (except_case(a, b, len))
		return ;
	pivot = setup_pivot(*b, len);
	while (len--)
	{
		if ((*b)->num >= pivot && ++push)
			push_a(a, b);
		else if ((*b)->num < pivot && ++rotate)
			rotate_b(b);
	}
	before_push(b, rotate);
	a_to_b(a, b, push);
	b_to_a(a, b, rotate);
}
