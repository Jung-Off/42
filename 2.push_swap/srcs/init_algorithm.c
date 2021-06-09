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

// 


void b_to_a(t_link **a, t_link **b, int len)
{
    int pivot;
    int rotate = 0;
    int push = 0;

    pivot = setup_pivot(*b, len);
    //printf("\nb to a | pivot | %d", pivot);
    // printf("---2 =%d\n", pivot);
    if(len == 1)
    {
        push_a(a,b);
        return ;
    }
    while(len--)
    {
        if((*b)->num >= pivot && ++push) 
            push_a(a,b);
        else if((*b)->num < pivot && ++rotate)
            rotate_b(b);
        // print_function(pivot, *a);
    }

    int copy = rotate;
    while(copy--)
        rrotate_b(b);
    // printf("\nA : ");
    // print_stack(*a);
    // printf("\nB : ");
    // print_stack(*b);
    // printf("\n");
    a_to_b(a, b, push);
    b_to_a(a, b, rotate);

}

void a_to_b(t_link **a, t_link **b, int len)
{
    int pivot;
    int rotate = 0;
    int push = 0;
    static int first;

    pivot = setup_pivot(*a, len);
    //printf("\na to b | pivot | %d", pivot);

    if(len == 1)
        return ;
    while(len--)
    {
        if((*a)->num < pivot && ++push) 
            push_b(a,b);
        else if((*a)->num >= pivot && ++rotate)
            rotate_a(a);
    }
    if (first++ != 0)
         before_push(a, rotate); //이걸 쓸려면 맨 처음에만 쓰기 가능

    // printf("\nA : ");
    // print_stack(*a);
    // printf("\nB : ");
    // print_stack(*b);
    // printf("\n");
    a_to_b(a, b, rotate);
    b_to_a(a, b, push);
}

void before_push(t_link **a, int rotate)
{
        while(rotate--)
            rrotate_a(a);
}

// void function3(t_link **stack_a, t_link **stack_b)
// {

// }


// void function3(t_link **stack_a, t_link **stack_b)
// {

// }



void go_algorithm(t_link **stack_a, t_link **stack_b, int num)
{
    a_to_b(stack_a, stack_b, num);
}

