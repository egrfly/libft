/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:08:01 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:37:48 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memrchr(const void *ptr, char c, size_t n)
{
	unsigned char	*unsigned_char_ptr;
	size_t			i;

	unsigned_char_ptr = (unsigned char *)ptr;
	i = n;
	while (i > 0)
	{
		i--;
		if (unsigned_char_ptr[i] == (unsigned char)c)
		{
			return (&unsigned_char_ptr[i]);
		}
	}
	return (NULL);
}
