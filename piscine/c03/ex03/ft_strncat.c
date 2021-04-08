/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 01:59:09 by jji               #+#    #+#             */
/*   Updated: 2020/12/01 02:53:02 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				d_i;
	unsigned int	s_i;

	d_i = 0;
	s_i = 0;
	while (dest[d_i] != '\0')
		++d_i;
	while (src[s_i] != '\0' && s_i < nb)
	{
		dest[d_i + s_i] = src[s_i];
		++s_i;
	}
	dest[d_i + s_i] = '\0';
	return (dest);
}
