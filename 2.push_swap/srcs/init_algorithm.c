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

void go_algorithm(t_link **stack_a, t_link **stack_b)
{
    //swap_a(*stack_a);
    //swap_ab(*stack_a, *stack_b);
    //명령어 생각

    rotate_a(stack_a);
    //rotate_ab(stack_a, stack_b);

    //rrotate_b(stack_b);
    rrotate_ab(stack_a, stack_b);

    // push_a(stack_a, stack_b);
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
}