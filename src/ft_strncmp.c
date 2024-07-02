/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:18:37 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:52:51 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*unsigned_char_str1;
	unsigned char	*unsigned_char_str2;
	size_t			i;

	if (str1 == str2)
		return (0);
	unsigned_char_str1 = (unsigned char *)str1;
	unsigned_char_str2 = (unsigned char *)str2;
	i = 0;
	while (i < n && unsigned_char_str1[i] && unsigned_char_str2[i]
		&& unsigned_char_str1[i] == unsigned_char_str2[i])
		i++;
	if (i < n)
		return (unsigned_char_str1[i] - unsigned_char_str2[i]);
	return (0);
}
