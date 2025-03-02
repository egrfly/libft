/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_tree_newnode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:57:47 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/01 20:55:00 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_binary_tree.h"
#include "ft_stdlib.h"

t_binary_tree_node	*ft_binary_tree_newnode(void *value)
{
	t_binary_tree_node	*node;

	node = ft_calloc(1, sizeof(t_binary_tree_node));
	if (!node)
		return (NULL);
	node->value = value;
	return (node);
}
