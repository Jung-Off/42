/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:21:23 by jji               #+#    #+#             */
/*   Updated: 2021/06/09 14:21:25 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/setup_pivot.h"

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