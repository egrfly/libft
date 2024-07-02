/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:49:13 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 16:46:46 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

void	*ft_calloc(size_t n, size_t size)
{
	size_t	byte_count;
	void	*ptr;

	byte_count = size * n;
	if (byte_count / size != n)
		return (NULL);
	ptr = malloc(byte_count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, byte_count);
	return (ptr);
}
