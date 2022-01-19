/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 11:08:05 by jji               #+#    #+#             */
/*   Updated: 2021/02/07 16:55:42 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	int i = 241;
	int m_i = -241;

	printf("print flag case\n");
	
	printf("%d\n", i);
	printf("%-d\n", i);	
	
	printf("print width\n");
	
	printf("%2d\n", i);
	printf("%5d\n", i);
	printf("%05d\n", i);

	printf("print minus flag case\n");
	
	printf("%d\n", m_i);
	printf("%-d\n", m_i);

	printf("print width\n");
	
	printf("%2d\n", m_i);
	printf("%5d\n", m_i);
	printf("%05d\n", m_i);
		
	printf("print width i: *\n");
	
	printf("%*d\n", 2, i);
	printf("%*d\n", 5, i);
	printf("%0*d\n", 2, i);
	printf("%0*d\n", 5, i);

	printf("print width m_i: *\n");
	
	printf("%*d\n", 2, m_i);
	printf("%*d\n", 5, m_i);
	printf("%0*d\n", 2, m_i);
	printf("%0*d\n", 5, m_i);
	
	
	printf("print precision i: \n");

	printf("%.2d\n", i);
	printf("%.5d\n", i);
	printf("%.2d\n", m_i);
	printf("%.5d\n", m_i);


	printf("print width + precision i : \n");
	
	printf("%2.2d\n", i);
	printf("%2.3d\n", i);
	printf("%2.4d\n", i);
	printf("%2.5d\n", i);
	printf("%3.2d\n", i);
	printf("%4.2d\n", i);
	printf("%5.2d\n", i);
	printf("%5.5d\n", i);
	
	printf("print width + precision m_i : \n");
	
	printf("%2.2d\n", m_i);
	printf("%2.3d\n", m_i);
	printf("%2.4d\n", m_i);
	printf("%2.5d\n", m_i);
	printf("%3.2d\n", m_i);
	printf("%4.2d\n", m_i);
	printf("%5.2d\n", m_i);
	printf("%5.5d\n", m_i);


	printf("width : 0\n"); 

	printf("%0.2d\n", m_i);
	printf("%0.3d\n", m_i);
	printf("%0.4d\n", m_i);
	printf("%0.5d\n", m_i);

	printf("%0.2d\n", i);
	printf("%0.3d\n", i);
	printf("%0.4d\n", i);
	printf("%0.5d\n", i);
	
	printf("width : -2\n");	

	printf("%-2.0d\n", i);
	printf("%-2.1d\n", i);
	printf("%-2.2d\n", i);
	printf("%-2.3d\n", i);
	printf("%-2.4d\n", i);
	printf("%-2.5d\n", i);
	

	printf("%-2.0d\n", m_i);	
	printf("%-2.1d\n", m_i);
	printf("%-2.2d\n", m_i);
	printf("%-2.3d\n", m_i);
	printf("%-2.4d\n", m_i);
	printf("%-2.5d\n", m_i);
	
printf("width : -4\n");

	printf("%-4.0d\n", i);
	printf("%-4.1d\n", i);
	printf("%-4.2d\n", i);
	printf("%-4.3d\n", i);
	printf("%-4.4d\n", i);
	printf("%-4.5d\n", i);

	
	printf("%-4.0d\n", m_i);
	printf("%-4.1d\n", m_i);
	printf("%-4.2d\n", m_i);
	printf("%-4.3d\n", m_i);
	printf("%-4.4d\n", m_i);	
	printf("%-4.5d\n", m_i);


printf("width : * = -2\n");

	
	printf("%-*.0d\n", -2, i);
	printf("%-*.1d\n", -2, i);
	printf("%-*.2d\n", -2, i);
	printf("%-*.3d\n", -2, i);
	printf("%-*.4d\n", -2, i);
	printf("%-*.5d\n", -2, i);
	
	printf("%-*.0d\n", -2, m_i);
	printf("%-*.1d\n", -2, m_i);
	printf("%-*.2d\n", -2, m_i);
	printf("%-*.3d\n", -2, m_i);
	printf("%-*.4d\n", -2, m_i);
	printf("%-*.5d\n", -2, m_i);

printf("width : * = -4\n");

	
	printf("%-*.0d\n", -4, i);
	printf("%-*.1d\n", -4, i);
	printf("%-*.2d\n", -4, i);
	printf("%-*.3d\n", -4, i);
	printf("%-*.4d\n", -4, i);
	printf("%-*.5d\n", -4, i);

	printf("%-*.0d\n", -4, m_i);
	printf("%-*.1d\n", -4, m_i);
	printf("%-*.2d\n", -4, m_i);
	printf("%-*.3d\n", -4, m_i);
	printf("%-*.4d\n", -4, m_i);
	printf("%-*.5d\n", -4, m_i);

printf("width : * = -0\n");

	
	printf("%-*.0d\n", -0, i);
	printf("%-*.1d\n", 0, i);
	printf("%-*.2d\n", 0, i);
	printf("%-*.3d\n", -0, i);
	printf("%-*.4d\n", 0, i);
	printf("%-*.5d\n", -0, i);
	
	printf("%-*.0d\n", -0, m_i);
	printf("%-*.1d\n", 0, m_i);
	printf("%-*.2d\n", -0, m_i);
	printf("%-*.3d\n", 0, m_i);
	printf("%-*.4d\n", 0, m_i);
	printf("%-*.5d\n", -0, m_i);


	return (0);
}
