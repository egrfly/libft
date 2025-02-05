/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:05:09 by emflynn           #+#    #+#             */
/*   Updated: 2025/02/05 00:39:45 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *list, void (*del)(void *))
{
	t_list_node	*current_node;
	t_list_node	*next_node;

	current_node = list->first;
	while (current_node)
	{
		next_node = current_node->next;
		ft_list_delnode(current_node, del);
		current_node = next_node;
	}
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
}
