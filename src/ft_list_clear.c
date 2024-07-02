/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:05:09 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 23:56:43 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *list, void (*del)(void *))
{
	t_node	*current_node;
	t_node	*next_node;

	current_node = list->head.next;
	while (current_node != &list->tail)
	{
		next_node = current_node->next;
		ft_list_delnode(current_node, del);
		current_node = next_node;
	}
	list->head.next = &list->tail;
	list->tail.prev = &list->head;
	list->size = 0;
}
