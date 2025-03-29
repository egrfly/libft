/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 19:43:09 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/29 19:58:06 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	ft_list_sort(t_list *list, int (*cmp)(const char *, const char *))
{
	t_list_node	*current_node;
	t_list_node	*next_node;

	current_node = list->first;
	while (current_node)
	{
		next_node = current_node->next;
		while (next_node)
		{
			if (cmp(current_node->value, next_node->value) > 0)
				ft_swap((char **)(&current_node->value),
					(char **)(&next_node->value));
			next_node = next_node->next;
		}
		current_node = current_node->next;
	}
}
