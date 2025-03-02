/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_newnode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:37:56 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/01 20:55:16 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include "ft_stdlib.h"

t_list_node	*ft_list_newnode(void *value)
{
	t_list_node	*node;

	node = ft_calloc(1, sizeof(t_list_node));
	if (!node)
		return (NULL);
	node->value = value;
	return (node);
}
