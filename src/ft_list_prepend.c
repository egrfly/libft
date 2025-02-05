/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_prepend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:44:11 by emflynn           #+#    #+#             */
/*   Updated: 2025/02/05 02:17:54 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_list.h"

bool	ft_list_prepend(t_list *list, void *value)
{
	t_list_node	*new_node;

	new_node = ft_list_newnode(value);
	if (!new_node)
		return (false);
	ft_list_prependnode(list, new_node);
	return (true);
}
