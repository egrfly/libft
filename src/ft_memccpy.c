/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:22:22 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:37:27 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dest, const void *src, char c, size_t n)
{
	unsigned char	*unsigned_char_ptr_dest;
	unsigned char	*unsigned_char_ptr_src;
	size_t			i;

	unsigned_char_ptr_dest = (unsigned char *)dest;
	unsigned_char_ptr_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		unsigned_char_ptr_dest[i] = unsigned_char_ptr_src[i];
		if (unsigned_char_ptr_dest[i] == (unsigned char)c)
			return (&unsigned_char_ptr_dest[i + 1]);
		i++;
	}
	return (NULL);
}
