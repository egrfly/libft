/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_appendnode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:55:15 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/01 20:51:41 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
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
