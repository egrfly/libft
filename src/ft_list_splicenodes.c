/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_splicenodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 21:00:44 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/07 09:15:38 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_splicenodes(t_list_node *last_of_first_list,
			t_list_node *first_of_second_list)
{
	t_list		*first_list;
	t_list		*second_list;

	first_list = last_of_first_list->parent;
	second_list = first_of_second_list->parent;
	ft_list_merge(first_list, second_list);
}
