/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:48:52 by jji               #+#    #+#             */
/*   Updated: 2021/03/29 18:55:19 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_STRUCT_H

# define MAKE_STRUCT_H

#include "../includes/main.h"
void make_struct(char **line,t_shape *shape);
void save_cycle(char **line, t_shape *shape);
int ft_atoi_moveaddress(char **str);

#endif
