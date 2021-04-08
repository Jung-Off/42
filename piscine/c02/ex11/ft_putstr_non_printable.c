/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:56:32 by jji               #+#    #+#             */
/*   Updated: 2020/12/01 02:32:59 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hex(unsigned char c)
{
	char *h_str;

	h_str = "0123456789abcedf";
	write(1, "\\", 1);
	write(1, &h_str[c / 16], 1);
	write(1, &h_str[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			hex(str[i]);
		++i;
	}
}
