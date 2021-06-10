/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:45:08 by jji               #+#    #+#             */
/*   Updated: 2021/05/26 17:45:10 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int ft_isnum(char str)
{
    if(str >= '0' && str <= '9')
        return (1);
    else
        return (0);
}

int push_atoi(char *str)
{
    long long sum;
    int minus;

    sum = 0;
    minus = 1;
    if(*str == '-' && str++)
        minus = -1;
    while(*str)
    {
        if(!ft_isnum(*str))
            error_check2();
        sum = sum * 10 + (*(str++) - '0');
    }
    sum *= minus;
    if(sum > 2147483647 || sum < -2147483648)
        error_check2();
    return (sum);
}


int max_3(t_link *a)
{
    int max;
    
    max = a->num;
    if (max < a->next->num)
        max = a->next->num;
    if (max < a->next->next->num)
        max = a->next->next->num;
    return (max);
}

int min_3(t_link *a)
{
    int min;
    
    min = a->num;
    if (min > a->next->num)
        min = a->next->num;
    if (min > a->next->next->num)
        min = a->next->next->num;
    return (min);
}

void num3_set(t_link **a, t_link **b, int num)
{
    int max;
    int min;

    max = max_3(*a);
    min = min_3(*a);
    if(max == ((*a)->next->num))
    {
        if (min == (*a)->num)
        {
            rotate_a(a);
            swap_a(*a);
        }    
        rrotate_a(a);
    }
    if (min == (*a)->next->num)
    {
        if (max == (*a)->num)
            rotate_a(a);
        else
            swap_a(*a);
    }
    if(max == (*a)->num)
    {   
        swap_a(*a);
        rrotate_a(a);
    }
}