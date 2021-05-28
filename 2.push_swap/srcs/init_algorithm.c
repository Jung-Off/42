/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:00:53 by jji               #+#    #+#             */
/*   Updated: 2021/05/27 15:00:54 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/init_algorithm.h"

int return_pivot(int *tmp, int i)
{
    int result;

    result = tmp[i];
    free(tmp);
    return (result);
}

int *input_arr(t_link *stack_a, int *tmp, int num)
{
    int i;

    i = 0;
    while (i < num)
    {
        tmp[i++] = stack_a->num;
        stack_a = stack_a->next;
    }
    return(tmp);
}

int	malloc_error2(int **tmp, int num)
{
	*tmp = malloc(sizeof(int) * num);

	if (*tmp == NULL)
		return (1);
	else
		return (0);
}

int setup_pivot(t_link *stack_a, int num)
{
    int *tmp;
    int i;
    int j;
    int count;

    if(malloc_error2(&tmp, num))
        exit(0);
    //예외처리
    tmp = input_arr(stack_a, tmp ,num);
    i = 0;
    while (i < num)
    {
        count = 0;
        j = 0;
        while (j < num)
        {
            if (tmp[i] > tmp[j])
                count++;
            ++j;
        }
        if (count == num / 2)
            return(return_pivot(tmp, i));
        i++;
    }
    return (return_pivot(tmp, 0));
}

void go_algorithm(t_link **stack_a, t_link **stack_b, int num)
{

    a_to_b(stack_a, stack_b, num);

    // b_to_a()
}

void b_to_a(t_link **a, t_link **b, int len)
{
    int pivot;
    int rotate = 0;
    int push = 0;

    pivot = setup_pivot(*a, len);
    if(len == 1)
    {
        push_a(a,b);
        return ;
    }
    while(len--)
    {
        if((*a)->num >= pivot && ++push) 
            push_a(a,b);
        else if((*a)->num < pivot && ++rotate)
            rotate_b(b);
        // print_function(pivot, *a);
    }

    int copy = rotate;
    while(copy--)
        rrotate_b(b);
    //  b_to_a(a, b, rotate);
    //  a_to_b(a, b, push);

}

void a_to_b(t_link **a, t_link **b, int len)
{
    int pivot;
    int rotate = 0;
    int  push = 0;

    pivot = setup_pivot(*a, len);
    if(len == 1)
        return ;
    while(len--)
    {
        if((*a)->num < pivot && ++push) 
            push_b(a,b);
        else if((*a)->num >= pivot && ++rotate)
            rotate_a(a);
        // print_function(pivot, *a);
    }
     int copy = rotate;
    while(copy--)
        rrotate_a(a);
    // printf("\n[[[[pivot %d]]]]", pivot);
    // printf("\na : ");
	// print_stack(*a);
	// printf("\nb : ");
	// print_stack(*b);
    a_to_b(a, b, rotate);
   b_to_a(a, b, push);
}



    //swap_a(*stack_a);
    //swap_ab(*stack_a, *stack_b);
    //명령어 생각
    //rotate_a(stack_a);
    //rotate_ab(stack_a, stack_b);
    //rrotate_b(stack_b);
    //rrotate_ab(stack_a, stack_b);
    //push_a(stack_a, stack_b);
//     push_b(stack_a, stack_b);
//     push_b(stack_a, stack_b);
//     push_b(stack_a, stack_b);
//     push_b(stack_a, stack_b);
//     push_b(stack_a, stack_b);
//     push_b(stack_a, stack_b);
//     push_b(stack_a, stack_b);
//     push_b(stack_a, stack_b);
//     push_a(stack_a, stack_b);
//     push_a(stack_a, stack_b);
