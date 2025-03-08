/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:40:09 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/08 03:25:52 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdbool.h>
# include <stdlib.h>

typedef void				(*t_action_func)(void *);
typedef void				*(*t_transformation_func)(void *);

typedef struct s_list_node	t_list_node;
typedef struct s_list		t_list;

struct s_list_node
{
	void		*value;
	t_list_node	*prev;
	t_list_node	*next;
	t_list		*parent;
};

struct s_list
{
	t_list_node	*first;
	t_list_node	*last;
	size_t		size;
};

bool		ft_list_append(t_list *list, void *value);
void		ft_list_appendnode(t_list *list, t_list_node *node);
void		ft_list_clear(t_list *list, void (*del)(void *));
void		ft_list_delnode(t_list_node *node, void (*del)(void *));
void		ft_list_destroy(t_list *list, void (*del)(void *));
t_list		*ft_list_init(void);
bool		ft_list_insert(t_list *list, unsigned int index,
				void *value);
bool		ft_list_insertnode(t_list *list, unsigned int index,
				t_list_node *node);
void		ft_list_iter(t_list *list, void (*f)(void *));
t_list		*ft_list_map(const t_list *list, void *(*f)(void *),
				void (*del)(void *));
void		ft_list_merge(t_list *first_list, t_list *second_list);
t_list_node	*ft_list_newnode(void *value);
void		*ft_list_pop(t_list *list);
bool		ft_list_prepend(t_list *list, void *value);
void		ft_list_prependnode(t_list *list, t_list_node *node);
void		ft_list_removenode(t_list *list, t_list_node *node);
t_list		*ft_list_shallowcopy(t_list *list);
size_t		ft_list_size(const t_list *list);
void		ft_list_splicenodes(t_list_node *last_of_first_list,
				t_list_node *first_of_second_list);

#endif
