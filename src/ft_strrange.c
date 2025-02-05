/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 23:33:25 by emflynn           #+#    #+#             */
/*   Updated: 2025/02/05 23:37:51 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrange(const char *str, unsigned int start, unsigned int end)
{
	if (end < start)
		return (ft_strdup(""));
	return (ft_substr(str, start, end - start));
}
