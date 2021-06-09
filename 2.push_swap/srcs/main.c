/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:22:53 by jji               #+#    #+#             */
/*   Updated: 2021/05/25 15:53:02 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

	//누수 테스트
	// t_link *test = stack_a->prev;
	// stack_a->prev->next = NULL;
	// stack_a_free(stack_a);
	// free(test);

static void print_function(int argc, t_link *stack)
{
	///>>>>>>>>>>/////
	
	int a = argc;

	if(!(stack))
		return;
	while(--a)
	{
		printf(" %d", stack->num);
		stack = stack->next;
	}
	//<<<<<<<<<<<///
	// while(argc--)
	// {
	// 	printf("%d\n", stack_a->num);
	// 	stack_a = stack_a->prev;
	// }
	//linke_number 애서 저장한 stack_a를 이용할 예정

}

void	print_stack(t_link *stack)
{
	t_link	*head;

	if (!stack)
		return ;
	head = stack;
	printf("%d ", stack->num);
	stack = stack->next;
	while (stack != head)
	{
		printf("%d ", stack->num);
		stack = stack->next;
	}
}

void decending_set(t_link **stack_a, t_link **stack_b, int num)
{
	int push_count;
	
	push_count = 0;
	while(num-- > 1)
	{
		push_b(stack_a,stack_b);
		push_count++;
	}
	while(push_count-- > 0)
	{
		push_a(stack_a, stack_b);
		rotate_a(stack_a);
	}
}

void go_algorithm(t_link **stack_a, t_link **stack_b, int num)
{
	
	if (decending_check(*stack_a, num))
	{
		decending_set(stack_a, stack_b, num);
		return ;
	}
	a_to_b(stack_a, stack_b, num);
}

int main(int argc, char **argv)
{
	t_link *stack_a;
	t_link *stack_b;

	stack_a = 0;
	stack_b = 0;
	error_check(argc, argv);

	if (link_number(argc, argv, &stack_a))
	{
		lst_free(stack_a);
		exit(1); //return (1);
	}

	go_algorithm(&stack_a, &stack_b, argc - 1);

	// printf("\na : ");
	// print_stack(stack_a);
	// printf("\nb : ");
	// print_stack(stack_b);

	return (0);
}
