/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:12:38 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 23:57:38 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_map(const t_list *list, void *(*f)(void *),
			void (*del)(void *))
{
	t_list	*map;
	t_node	*current_node;
	t_node	*new_node;
	void	*new_content;

	map = ft_list_init();
	if (!map)
		return (NULL);
	current_node = list->head.next;
	while (current_node != &list->tail)
	{
		new_content = f(current_node->content);
		new_node = ft_list_newnode(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_list_destroy(map, del);
			return (NULL);
		}
		ft_list_append(map, new_node);
		current_node = current_node->next;
	}
	map->size = list->size;
	return (map);
}
