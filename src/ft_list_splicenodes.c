/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_splicenodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:00:44 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/01 21:08:56 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_splicenodes(t_list_node *last_of_first_list,
			t_list_node *first_of_second_list)
{
	t_list		*first_list;
	t_list		*second_list;
	t_list_node	*current;

	first_list = last_of_first_list->parent;
	second_list = first_of_second_list->parent;
	last_of_first_list->next = first_of_second_list;
	first_of_second_list->prev = last_of_first_list;
	first_list->last = second_list->last;
	current = first_of_second_list;
	while (current)
	{
		current->parent = first_list;
		current = current->next;
	}
	free(second_list);
}
