/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:00:44 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/07 09:14:00 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_merge(t_list *first_list, t_list *second_list)
{
	t_list_node	*current;

	if (first_list->size > 0)
		first_list->last->next = second_list->first;
	else
		first_list->first = second_list->first;
	if (second_list->size > 0)
	{
		second_list->first->prev = first_list->last;
		first_list->last = second_list->last;
	}
	current = second_list->first;
	while (current)
	{
		current->parent = first_list;
		current = current->next;
	}
	first_list->size += second_list->size;
	free(second_list);
}
