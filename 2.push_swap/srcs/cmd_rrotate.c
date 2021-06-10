/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:44:42 by jji               #+#    #+#             */
/*   Updated: 2021/06/10 20:44:39 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cmd_rrotate.h"

void	rrotate_a(t_link **stack_a)
{
	t_link *head;

	if (!(*stack_a))
		return ;
	head = (*stack_a)->prev;
	(*stack_a) = head;
	write(1, "rra\n", 4);
}

void	rrotate_b(t_link **stack_b)
{
	t_link *head;

	if (!(*stack_b))
		return ;
	head = (*stack_b)->prev;
	(*stack_b) = head;
	write(1, "rrb\n", 4);
}

void	rrotate_ab(t_link **stack_a, t_link **stack_b)
{
	rrotate_a(stack_a);
	rrotate_b(stack_b);
}
