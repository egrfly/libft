/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:19:06 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:53:07 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strnlen(str, n) + 1));
	if (!dup)
		return (NULL);
	ft_strncpy(dup, str, n);
	return (dup);
}
