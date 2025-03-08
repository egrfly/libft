/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insertnode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:55:15 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/08 03:52:21 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_list.h"

bool	ft_list_insertnode(t_list *list, unsigned int index, t_list_node *node)
{
	t_list_node		*node_to_insert_before;
	unsigned int	i;

	if (index > list->size)
		return (false);
	if (index == 0)
		return (ft_list_prependnode(list, node), true);
	if (index == list->size)
		return (ft_list_appendnode(list, node), true);
	node_to_insert_before = list->first;
	i = 0;
	while (i < index)
	{
		node_to_insert_before = node_to_insert_before->next;
		i++;
	}
	node->prev = node_to_insert_before->prev;
	node->next = node_to_insert_before;
	node_to_insert_before->prev->next = node;
	node_to_insert_before->prev = node;
	list->size++;
	node->parent = list;
	return (true);
}
