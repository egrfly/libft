/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 21:10:41 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:06:42 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*unsigned_char_ptr1;
	unsigned char	*unsigned_char_ptr2;
	size_t			i;

	if (ptr1 == ptr2)
		return (0);
	unsigned_char_ptr1 = (unsigned char *)ptr1;
	unsigned_char_ptr2 = (unsigned char *)ptr2;
	i = 0;
	while (i < n)
	{
		if (unsigned_char_ptr1[i] != unsigned_char_ptr2[i])
			return (unsigned_char_ptr1[i] - unsigned_char_ptr2[i]);
		i++;
	}
	return (0);
}
