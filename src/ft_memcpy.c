/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:33:47 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:08:49 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*unsigned_char_ptr_dest;
	unsigned char	*unsigned_char_ptr_src;
	size_t			i;

	if (dest == src)
		return (dest);
	unsigned_char_ptr_dest = (unsigned char *)dest;
	unsigned_char_ptr_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		unsigned_char_ptr_dest[i] = unsigned_char_ptr_src[i];
		i++;
	}
	return (dest);
}
