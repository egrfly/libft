/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:52:26 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 23:40:50 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_node	*ft_list_last(const t_list *list)
{
	if (list->tail.prev != &list->head)
		return (list->tail.prev);
	else
		return (NULL);
}
