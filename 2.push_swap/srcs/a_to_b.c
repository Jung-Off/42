/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:00:53 by jji               #+#    #+#             */
/*   Updated: 2021/06/10 20:59:50 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/a_to_b.h"

static void	before_push(t_link **a, int rotate)
{
	while (rotate--)
		rrotate_a(a);
}

static void	set_2(t_link **a)
{
	if ((*a)->num > (*a)->next->num)
		swap_a(*a);
}

static void	set_3(t_link **a, t_link **b)
{
	if ((*a)->num == max_3(*a))
		swap_a(*a);
	if ((*a)->num == min_3(*a))
	{
		if (ascending_check_len(*a, 3))
			return ;
		else
		{
			rotate_a(a);
			swap_a(*a);
			rrotate_a(a);
		}
	}
	else
	{
		if ((*a)->next->num == min_3(*a))
			swap_a(*a);
		else
		{
			push_b(a, b);
			swap_a(*a);
			push_a(a, b);
			swap_a(*a);
		}
	}
}

static int	except_case(t_link **a, t_link **b, int len)
{
	if (len == 1)
		return (1);
	else if (len == 2)
	{
		set_2(a);
		return (1);
	}
	else if (len == 3)
	{
		set_3(a, b);
		return (1);
	}
	return (0);
}

void		a_to_b(t_link **a, t_link **b, int len)
{
	int			pivot;
	int			rotate;
	int			push;
	static int	first;

	rotate = 0;
	push = 0;
	if (except_case(a, b, len))
		return ;
	pivot = setup_pivot(*a, len);
	while (len--)
	{
		if ((*a)->num < pivot && ++push)
			push_b(a, b);
		else if ((*a)->num >= pivot && ++rotate)
			rotate_a(a);
	}
	if (first++ != 0)
		before_push(a, rotate);
	a_to_b(a, b, rotate);
	b_to_a(a, b, push);
}
