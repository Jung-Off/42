/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jji <jji@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:09:50 by jji               #+#    #+#             */
/*   Updated: 2021/06/10 20:28:01 by jji              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_LIST_H
# define MAKE_LIST_H

# include "main.h"

void	make_node(t_link **lst);
void	add_node(t_link **lst, t_link *new_lst);
void	last_to_first(t_link **lst);

#endif
