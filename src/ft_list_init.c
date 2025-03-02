/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 23:37:56 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/01 20:55:09 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_stdlib.h"

t_list	*ft_list_init(void)
{
	t_list	*list;

	list = ft_calloc(1, sizeof(t_list));
	return (list);
}
