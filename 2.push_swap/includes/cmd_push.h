/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:50:21 by jji               #+#    #+#             */
/*   Updated: 2021/05/27 15:50:22 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CMD_PUSH_H
# define CMD_PUSH_H

# include "main.h"

// void push_a(t_link **stack_a, t_link **stack_b);
void    push_b(t_link **stack_a, t_link **stack_b);
t_link *pop_function(t_link **stack);
void    push_function(t_link **stack, t_link *top);
void    push_a(t_link **stack_a, t_link **stack_b);

#endif