/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:04:18 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:37:38 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *ptr, char c, size_t n)
{
	unsigned char	*unsigned_char_ptr;
	size_t			i;

	unsigned_char_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if (unsigned_char_ptr[i] == (unsigned char)c)
			return (&unsigned_char_ptr[i]);
		i++;
	}
	return (NULL);
}
