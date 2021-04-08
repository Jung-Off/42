/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 04:18:45 by jji               #+#    #+#             */
/*   Updated: 2021/01/10 04:39:13 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int word_num(const char *s, char c)
{	
	int i;
	int state;
	int count;

	count = 0;
	state = 0;
	i = 0;
	while(s[i])
	{
		if(s[i] != c && state == 0)
		{
			++count;
			state = 1;
		}
		if(s[i] == c)
		{
			state = 0;
		}
		++i;
	}
	return (count);
}

void *do_free(char **dum, int i)
{
	int j;

	j = 0;
	while(j < i)
	{
		free(dum[j]);
		++j;
	}
	free(dum);
	return (0);
}

void do_split(char **new_s, char const *s, char c)
{
	int i;
	int j;
	int pin;

	i = 0;
	j = 0;
	while(s[i])
	{
		if(s[i] != c && s[i] != 0)
		{	
			pin = i;
			while(s[i] != c && s[i] != 0)
				++i;
			if((new_s[j] = (char*)malloc(sizeof(char) * (i - pin + 1))) == 0)
			{
				do_free(new_s, j);
				return ;
			}
			ft_strlcpy(new_s[j++], s + pin, i - pin + 1);		
		}
		else if(s[i] != 0)
			++i;
	}
}
char **ft_split(char const *s, char c)
{
	int num;
	char **new_s;

	if(s == 0)
		return (0);
	num = word_num(s,c);
	if(!(new_s = (char**)malloc(sizeof(char*) * num + 1)))
		return (0);
	new_s[num] = 0;
	if(num == 0)
		return(new_s);
	do_split(new_s, s, c);

	return(new_s);
}
