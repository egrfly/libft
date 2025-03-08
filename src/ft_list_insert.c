/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:55:15 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/08 03:22:21 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_list.h"

bool	ft_list_insert(t_list *list, unsigned int index, void *value)
{
	t_list_node	*new_node;

	if (index > list->size)
		return (false);
	new_node = ft_list_newnode(value);
	if (!new_node)
		return (false);
	ft_list_insertnode(list, index, new_node);
	return (true);
}
