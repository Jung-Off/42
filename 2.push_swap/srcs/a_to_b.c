/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:00:53 by jji               #+#    #+#             */
/*   Updated: 2021/06/09 20:16:22 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/a_to_b.h"

// 
static void before_push(t_link **a, int rotate)
{
        while(rotate--)
            rrotate_a(a);
}

static void set_last(t_link **a)
{
    if((*a)->num > (*a)->next->num)
        swap_a(*a);
}

static int except_case(t_link **a, int len)
{
    if (len == 1)
        return (1);
    if (len == 2)
    {
        set_last(a);
        return (1);
    }
    return (0);
}

void a_to_b(t_link **a, t_link **b, int len)
{
    int pivot;
    int rotate;
    int push;
    static int first;
    
    rotate = 0;
    push = 0;
    pivot = setup_pivot(*a, len);
    if (except_case(a, len))
        return ;
    while(len--)
    {
        if((*a)->num < pivot && ++push) 
            push_b(a,b);
        else if((*a)->num >= pivot && ++rotate)
            rotate_a(a);
    }
    if (first++ != 0)
         before_push(a, rotate);
    a_to_b(a, b, rotate);
    b_to_a(a, b, push);
}



