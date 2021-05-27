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
}

void push_a(t_link **stack_a, t_link **stack_b)
{
    if(!(*stack_b))
        return ;
    push_function(stack_a, pop_function(stack_b));
}


// void push_b(t_link **stack_a, t_link **stack_b)
// {
//     t_link *top;

//     if(!(*stack_a))
//         return ;
//     top = *stack_a;
//     *stack_a = (*stack_a)->next;
//     top->prev->next = (*stack_a);
//     top->next->prev = top->prev;
//     if(top->next == top)
//         *stack_a = NULL;

//     if(!(*stack_b))
//     {
//         *stack_b = top;
//         top->next = top;
//         top->prev = top;
//         return;
//     }
//     (*stack_b)->prev->next = top;
//     top->prev = (*stack_b)->prev; 
//     (*stack_b)->prev = top;
//     top->next = (*stack_b);
//     *stack_b = (*stack_b)->prev;
// }



// void push_a(t_link **stack_a, t_link **stack_b)
// {

// }