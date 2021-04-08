/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:45:28 by jji               #+#    #+#             */
/*   Updated: 2021/03/29 18:48:32 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include <fcntl.h> //open
#include <stdio.h> //printf
#include <string.h>
#include "../libft/libft.h"
#include "parse_line.h"
#include "make_struct.h"

typedef struct 	s_sp
{
	double x;
	double y;
	double z;
	double r;
	double red;
	double green;
	double blue;
}				t_sp;


typedef struct 	s_shape
{
	t_sp cycle;
}				t_shape;


#endif
