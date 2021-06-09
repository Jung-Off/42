/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:20:34 by jji               #+#    #+#             */
/*   Updated: 2021/05/27 14:20:35 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cmd_swap.h"

void ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void swap_a(t_link *stack_a)
{
    t_link *bottom;

    if(!stack_a)
        return ;
    bottom = stack_a->next;
    ft_swap(&(stack_a->num), &(bottom->num));
    write(1, "sa\n", 3);
}

void swap_b(t_link *stack_b)
{
    t_link *bottom;

    if(!stack_b)
        return ;
    bottom = stack_b->next;
    ft_swap(&(stack_b->num), &(bottom->num));
    write(1, "sb\n", 3);
}

void swap_ab(t_link *stack_a, t_link *stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
    //write(1, "ss\n", 3);
}