/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:34:29 by jji               #+#    #+#             */
/*   Updated: 2021/06/10 20:43:37 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cmd_rotate.h"

void	rotate_a(t_link **stack_a)
{
	t_link *head;

	if (!(*stack_a))
		return ;
	head = (*stack_a)->next;
	(*stack_a) = head;
	write(1, "ra\n", 3);
}

void	rotate_b(t_link **stack_b)
{
	t_link *head;

	if (!(*stack_b))
		return ;
	head = (*stack_b)->next;
	(*stack_b) = head;
	write(1, "rb\n", 3);
}

void	rotate_ab(t_link **stack_a, t_link **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
