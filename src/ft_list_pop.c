/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:14:07 by emflynn           #+#    #+#             */
/*   Updated: 2025/02/12 15:18:38 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	*ft_list_pop(t_list *list)
{
	t_list_node	*last;
	void		*last_value;

	last = list->last;
	if (last)
	{
		last_value = last->value;
		ft_list_removenode(list, last);
		free(last);
		return (last_value);
	}
	return (NULL);
}
