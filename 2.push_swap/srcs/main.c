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

static void print_function(int argc, t_link *stack_a, t_link *stack_b)
{
	///>>>>>>>>>>/////
	
	int a = argc;
	printf("\nb : ");
	while(--a)
	{
		printf(" %d", stack_b->num);
		stack_b = stack_b->next;
	}
	a = argc;
	printf("\na : ");
	while(--a)
	{
		printf(" %d", stack_a->num);
		stack_a = stack_a->next;
	}
	a = argc;

	
	//<<<<<<<<<<<///
	// while(argc--)
	// {
	// 	printf("%d\n", stack_a->num);
	// 	stack_a = stack_a->prev;
	// }
	//linke_number 애서 저장한 stack_a를 이용할 예정

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
	
	go_algorithm(&stack_a, &stack_b);
	print_function(argc, stack_a, stack_b);

	return (0);
}
