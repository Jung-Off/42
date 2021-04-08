/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 23:21:29 by jji               #+#    #+#             */
/*   Updated: 2020/11/30 21:07:12 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int len;

	len = 0;
	while (len < n)
	{
		if (*(src + len) == '\0')
		{
			while (len < n)
			{
				*(dest + len) = '\0';
				++len;
			}
		}
		else
		{
			*(dest + len) = *(src + len);
			++len;
		}
	}
	return (dest);
}
