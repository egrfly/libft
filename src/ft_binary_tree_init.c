/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_tree_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:37:56 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/02 00:17:24 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_binary_tree.h"
#include "ft_stdlib.h"

t_binary_tree	*ft_binary_tree_init(void)
{
	t_binary_tree	*binary_tree;

	binary_tree = ft_calloc(1, sizeof(t_binary_tree));
	return (binary_tree);
}
