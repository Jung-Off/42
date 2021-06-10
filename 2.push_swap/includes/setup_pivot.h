/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pivot.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 14:22:45 by jji               #+#    #+#             */
/*   Updated: 2021/06/10 20:29:46 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_PIVOT_H
# define SETUP_PIVOT_H

# include "main.h"

int	setup_pivot(t_link *stack_a, int num);
int	*input_arr(t_link *stack_a, int *tmp, int num);
int	return_pivot(int *tmp, int i);

#endif
