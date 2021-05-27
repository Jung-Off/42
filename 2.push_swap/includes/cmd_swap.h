/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 14:20:24 by jji               #+#    #+#             */
/*   Updated: 2021/05/27 14:20:25 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CMD_SWAP_H
# define CMD_SWAP_H

# include "main.h"

void ft_swap(int *a, int *b);
void swap_a(t_link *stack_a);
void swap_b(t_link *stack_b);
void swap_ab(t_link *stack_a, t_link *stack_b);

#endif