/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:31:15 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:57:19 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

size_t	ft_strspn(const char *str, const char *accept)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(accept, str[i]))
			return (i);
		i++;
	}
	return (i);
}
