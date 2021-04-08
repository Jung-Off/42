/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:56:12 by jji               #+#    #+#             */
/*   Updated: 2020/11/23 16:30:47 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_num(char hun, char num, char p)
{
	ft_putchar(hun);
	ft_putchar(num);
	ft_putchar(p);
}

void	ft_print_comb(void)
{
	char hun;
	char num;
	char p;

	hun = '0';
	while (hun <= '7')
	{
		num = hun + 1;
		while (num <= '8')
		{
			p = num + 1;
			while (p <= '9')
			{
				print_num(hun, num, p);
				if (hun == '7' && num == '8' && p == '9')
					break ;
				ft_putchar(',');
				ft_putchar(' ');
				p++;
			}
			++num;
		}
		++hun;
	}
}
