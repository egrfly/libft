/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:36:24 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:09:47 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*unsigned_char_ptr_dest;
	unsigned char	*unsigned_char_ptr_src;
	size_t			i;

	if (dest > src)
	{
		unsigned_char_ptr_dest = (unsigned char *)dest;
		unsigned_char_ptr_src = (unsigned char *)src;
		i = n;
		while (i > 0)
		{
			i--;
			unsigned_char_ptr_dest[i] = unsigned_char_ptr_src[i];
		}
		return (dest);
	}
	else
		return (ft_memcpy(dest, src, n));
}
