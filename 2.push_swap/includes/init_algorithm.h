/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algorithm.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:01:55 by jji               #+#    #+#             */
/*   Updated: 2021/05/27 15:01:57 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_ALGORITHM_H
# define INIT_ALGORITHM_H

# include "main.h"

void    go_algorithm(t_link **stack_a, t_link **stack_b, int num);
void    before_push(t_link **a, int rotate);
void    a_to_b(t_link **a, t_link **b, int pivot);


#endif