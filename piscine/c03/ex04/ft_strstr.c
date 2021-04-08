/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 02:54:04 by jji               #+#    #+#             */
/*   Updated: 2020/12/02 15:44:49 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0 && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

int		ft_len(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int size;

	i = 0;
	if (*to_find == '\0')
		return (str);
	size = ft_len(to_find);
	while (str[i] != 0)
	{
		if (str[i] == *to_find)
		{
			if (ft_strncmp(str + i, to_find, size) == 0)
				return (str + i);
		}
		i++;
	}
	return (0);
}
