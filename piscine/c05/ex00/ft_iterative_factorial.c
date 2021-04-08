/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:32:50 by jji               #+#    #+#             */
/*   Updated: 2020/12/02 12:24:01 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int temp;

	temp = nb - 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	while (temp > 1)
	{
		nb = nb * temp;
		--temp;
	}
	return (nb);
}
