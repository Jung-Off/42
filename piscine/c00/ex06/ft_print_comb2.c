/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:46:38 by jji               #+#    #+#             */
/*   Updated: 2020/11/23 22:11:55 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_num(int num_1, int num_2)
{
	int re_1;
	int re_2;
	int mod_1;
	int mod_2;

	re_1 = num_1 / 10 + '0';
	mod_1 = num_1 % 10 + '0';
	re_2 = num_2 / 10 + '0';
	mod_2 = num_2 % 10 + '0';
	ft_putchar(re_1);
	ft_putchar(mod_1);
	ft_putchar(' ');
	ft_putchar(re_2);
	ft_putchar(mod_2);
}

void	ft_print_comb2(void)
{
	int num_1;
	int num_2;

	num_1 = 0;
	while (num_1 <= 98)
	{
		num_2 = num_1 + 1;
		while (num_2 <= 99)
		{
			print_num(num_1, num_2);
			if (num_1 != 98 || num_2 != 99)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			++num_2;
		}
		++num_1;
	}
}
