/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:54:08 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:37:56 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *ptr, char c, size_t n)
{
	unsigned char	*unsigned_char_ptr;
	size_t			i;

	unsigned_char_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		unsigned_char_ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
