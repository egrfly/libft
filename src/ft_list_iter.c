/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:08:39 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 23:47:12 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_iter(t_list *list, void (*f)(void *))
{
	t_node	*current_node;

	current_node = list->head.next;
	while (current_node != &list->tail)
	{
		f(current_node->content);
		current_node = current_node->next;
	}
}
