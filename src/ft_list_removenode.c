/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_removenode.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:55:15 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/01 20:53:22 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_removenode(t_list *list, t_list_node *node)
{
	if (node->prev)
		node->prev->next = node->next;
	else
		list->first = node->next;
	if (node->next)
		node->next->prev = node->prev;
	else
		list->last = node->prev;
	list->size--;
	node->parent = NULL;
}
