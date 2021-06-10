/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:22:53 by jji               #+#    #+#             */
/*   Updated: 2021/06/10 20:51:25 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	decending_set(t_link **stack_a, t_link **stack_b, int num)
{
	int push_count;

	push_count = 0;
	while (num-- > 1)
	{
		push_b(stack_a, stack_b);
		push_count++;
	}
	while (push_count-- > 0)
	{
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
	}
}

void	go_algorithm(t_link **stack_a, t_link **stack_b, int num)
{
	if (num == 3)
	{
		num3_set(stack_a, stack_b);
		return ;
	}
	if (decending_check(*stack_a, num))
	{
		if (num == 2)
		{
			swap_a(*stack_a);
			return ;
		}
		decending_set(stack_a, stack_b, num);
		return ;
	}
	else
		a_to_b(stack_a, stack_b, num);
}

int		main(int argc, char **argv)
{
	t_link *stack_a;
	t_link *stack_b;

	stack_a = 0;
	stack_b = 0;
	error_check(argc, argv);
	if (link_number(argc, argv, &stack_a))
	{
		lst_free(stack_a);
		exit(1);
	}
	go_algorithm(&stack_a, &stack_b, argc - 1);
	return (0);
}
