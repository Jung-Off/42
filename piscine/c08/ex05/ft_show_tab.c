/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:11:02 by jji               #+#    #+#             */
/*   Updated: 2020/12/09 15:27:03 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void				ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void				ft_putnum(int num)
{
	if (num > 9)
		ft_putnum(num / 10);
	write(1, &"0123456789"[num % 10], 1);
}

void				ft_show_tab(struct s_stock_str *par)
{
	int	index;

	index = 0;
	while (par[index].str != 0)
	{
		ft_putstr(par[index].str);
		ft_putstr("\n");
		ft_putnum(par[index].size);
		ft_putstr("\n");
		ft_putstr(par[index].copy);
		ft_putstr("\n");
		index++;
	}
}
