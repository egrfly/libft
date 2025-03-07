/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_shallowcopy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 08:34:46 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/07 08:36:10 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

static void	*map_to_self(void *value)
{
	return (value);
}

t_list	*ft_list_shallowcopy(t_list *list)
{
	return (ft_list_map(list, map_to_self, NULL));
}
