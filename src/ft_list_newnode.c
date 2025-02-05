/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_newnode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:37:56 by emflynn           #+#    #+#             */
/*   Updated: 2025/02/05 00:17:52 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include "ft_stdlib.h"

t_list_node	*ft_list_newnode(void *value)
{
	t_list_node	*node;

	node = ft_calloc(sizeof(t_list_node), 1);
	if (!node)
		return (NULL);
	node->value = value;
	return (node);
}
