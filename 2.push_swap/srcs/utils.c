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
    if (str >= '0' && str <= '9')
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
    if (*str == '-' && str++)
        minus = -1;
    while (*str)
    {
        if (!ft_isnum(*str))
            error_check2();
        sum = sum * 10 + (*(str++) - '0');
    }
    sum *= minus;
    if (sum > 2147483647 || sum < -2147483648)
        error_check2();
    return (sum);
}

