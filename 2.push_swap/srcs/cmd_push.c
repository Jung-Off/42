/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:50:14 by jji               #+#    #+#             */
/*   Updated: 2021/05/27 15:50:15 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cmd_push.h"

void push_b(t_link **stack_a, t_link **stack_b)
{
    t_link *a_top;

    if(!(*stack_a))
        return ;
    a_top = *stack_a;
    *stack_a = (*stack_a)->next;
    a_top->prev->next = (*stack_a);
    a_top->next->prev = a_top->prev;
    if(a_top->next == a_top)
        *stack_a = NULL;

        
    if(!(*stack_b))
    {
        *stack_b = a_top;
        a_top->next = a_top;
        a_top->prev = a_top;
        return;
    }
    (*stack_b)->prev->next = a_top;
    a_top->prev = (*stack_b)->prev; 
    (*stack_b)->prev = a_top;
    a_top->next = (*stack_b);
    *stack_b = (*stack_b)->prev;
}

// void push_a(t_link **stack_a, t_link **stack_b)
// {

// }