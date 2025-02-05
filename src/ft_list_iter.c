/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 00:08:39 by emflynn           #+#    #+#             */
/*   Updated: 2025/02/05 00:22:30 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_iter(t_list *list, void (*f)(void *))
{
	t_list_node	*current_node;

	current_node = list->first;
	while (current_node)
	{
		f(current_node->value);
		current_node = current_node->next;
	}
}
