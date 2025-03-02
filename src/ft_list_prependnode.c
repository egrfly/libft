/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_prependnode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:44:11 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/01 20:53:05 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_list.h"

void	ft_list_prependnode(t_list *list, t_list_node *node)
{
	if (!list->last)
		list->last = node;
	else
	{
		node->next = list->first;
		list->first->prev = node;
	}
	list->first = node;
	list->size++;
	node->parent = list;
}
