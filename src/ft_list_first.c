/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:52:26 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 23:40:45 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_node	*ft_list_first(const t_list *list)
{
	if (list->head.next != &list->tail)
		return (list->head.next);
	else
		return (NULL);
}
