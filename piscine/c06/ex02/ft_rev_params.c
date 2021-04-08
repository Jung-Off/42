/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:56:47 by jji               #+#    #+#             */
/*   Updated: 2020/12/03 06:13:14 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		++i;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (argc - 1 - i != 0)
		{
			ft_putstr(argv[argc - 1 - i]);
			ft_putchar('\n');
		}
		++i;
	}
	return (0);
}
