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

t_link *pop_function(t_link **stack)
{
    t_link *top;

    top = *stack;
    (*stack)->prev->next = (*stack)->next;
    (*stack)->next->prev = (*stack)->prev;
    (*stack) = (*stack)->next;

    if(top->next == top)
        *stack = NULL;
    top->next = top;
    top->prev = top;

    return(top);
}

void push_function(t_link **stack, t_link *top)
{
    if(!(*stack))
    {
        *stack = top;
        return ;
    }
    (*stack)->prev->next = top;
    top->prev = (*stack)->prev;
    (*stack)->prev = top;
    top->next = (*stack);
    *stack = (*stack)->prev;
}

void push_b(t_link **stack_a, t_link **stack_b)
{
    if(!(*stack_a))
        return ;
    push_function(stack_b, pop_function(stack_a));
    write(1, "pb\n", 3);
}

void push_a(t_link **stack_a, t_link **stack_b)
{
    if(!(*stack_b))
        return ;
    push_function(stack_a, pop_function(stack_b));
    write(1, "pa\n", 3);
}
