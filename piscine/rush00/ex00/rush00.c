/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seshin <seshin@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:43:52 by seshin            #+#    #+#             */
/*   Updated: 2020/11/22 02:03:27 by seshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	pr_char(int *p, char a, char b);

void	rush(int x, int y)
{
	int j;

	j = 0;
	while (1)
	{
		if (j == 0 || j == y - 1)
		{
			pr_char(&x, 'o', '-');
			++j;
		}
		else if (j > 0 && j < y - 1)
		{
			pr_char(&x, '|', ' ');
			++j;
		}
		else
			break ;
	}
}

void	pr_char(int *num, char a, char b)
{
	int i;

	i = 1;
	while (i <= *num)
	{
		if (i == 1 || i == *num)
			ft_putchar(a);
		else
			ft_putchar(b);
		++i;
	}
	ft_putchar('\n');
}
