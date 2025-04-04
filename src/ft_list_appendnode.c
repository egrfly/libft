/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_appendnode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:55:15 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/08 03:19:18 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_appendnode(t_list *list, t_list_node *node)
{
	if (!list->first)
		list->first = node;
	else
	{
		node->prev = list->last;
		list->last->next = node;
	}
	list->last = node;
	list->size++;
	node->parent = list;
}
