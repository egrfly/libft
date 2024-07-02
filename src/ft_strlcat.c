/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 22:51:33 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:45:40 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n && dest[i])
		i++;
	j = 0;
	while (i + j + 1 < n && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i + j < n)
		dest[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
