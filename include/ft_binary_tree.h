/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_tree.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:12:54 by emflynn           #+#    #+#             */
/*   Updated: 2025/02/20 21:53:12 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARY_TREE_H
# define FT_BINARY_TREE_H

typedef struct s_binary_tree_node	t_binary_tree_node;
typedef struct s_binary_tree		t_binary_tree;

struct s_binary_tree_node
{
	void				*value;
	t_binary_tree_node	*parent;
	t_binary_tree_node	*primary_child;
	t_binary_tree_node	*secondary_child;
};

struct s_binary_tree
{
	t_binary_tree_node	*root;
};

t_binary_tree		*ft_binary_tree_init(void);
t_binary_tree_node	*ft_binary_tree_newnode(void *value);

#endif
