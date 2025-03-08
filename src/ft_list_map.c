/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:12:38 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/08 03:43:00 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_map(const t_list *list, void *(*f)(void *),
			void (*del)(void *))
{
	t_list		*new_list;
	t_list_node	*current_node;
	void		*new_value;

	new_list = ft_list_init();
	if (!new_list)
		return (NULL);
	current_node = list->first;
	while (current_node)
	{
		new_value = f(current_node->value);
		if (!ft_list_append(new_list, new_value))
		{
			if (del)
				del(new_value);
			ft_list_destroy(new_list, del);
			return (NULL);
		}
		current_node = current_node->next;
	}
	new_list->size = list->size;
	return (new_list);
}
