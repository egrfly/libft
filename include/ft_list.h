/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:40:09 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 23:58:01 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	t_node	head;
	t_node	tail;
	size_t	size;
}	t_list;

void	ft_list_append(t_list *list, t_node *node);
void	ft_list_prepend(t_list *list, t_node *node);
void	ft_list_clear(t_list *list, void (*del)(void *));
void	ft_list_delnode(t_node *node, void (*del)(void *));
void	ft_list_destroy(t_list *list, void (*del)(void *));
t_node	*ft_list_first(const t_list *list);
t_list	*ft_list_init(void);
void	ft_list_iter(t_list *list, void (*f)(void *));
t_node	*ft_list_last(const t_list *list);
t_list	*ft_list_map(const t_list *list, void *(*f)(void *),
			void (*del)(void *));
t_node	*ft_list_newnode(void *content);
void	ft_list_remove(t_list *list, t_node *node);
size_t	ft_list_size(const t_list *list);

#endif
