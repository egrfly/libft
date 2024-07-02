/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:33:22 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:41:10 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

size_t	ft_strcspn(const char *str, const char *reject)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr(reject, str[i]))
			return (i);
		i++;
	}
	return (i);
}
