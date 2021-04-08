/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 02:38:57 by jji               #+#    #+#             */
/*   Updated: 2020/12/07 02:54:05 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_str_length(char *str)
{
	int index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int		ft_compute_length(char **string, int size, int sep_len)
{
	int final_len;
	int index;

	final_len = 0;
	index = 0;
	while (index < size)
	{
		final_len += ft_str_length(string[index]);
		final_len += sep_len;
		index++;
	}
	final_len -= sep_len;
	return (final_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		full_len;
	int		index;
	char	*head_address;
	char	*string;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	full_len = ft_compute_length(strs, size, ft_str_length(sep));
	if (!(string = (char *)malloc((full_len + 1) * sizeof(char))))
		return (0);
	head_address = string;
	index = 0;
	while (index < size)
	{
		ft_strcpy(head_address, strs[index]);
		head_address += ft_str_length(strs[index]);
		if (index < size - 1)
		{
			ft_strcpy(head_address, sep);
			head_address += ft_str_length(sep);
		}
		index++;
	}
	*head_address = '\0';
	return (string);
}
