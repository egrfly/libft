/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:09:49 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:39:23 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned char	*unsigned_char_str1;
	unsigned char	*unsigned_char_str2;
	unsigned int	i;

	if (str1 == str2)
		return (0);
	unsigned_char_str1 = (unsigned char *)str1;
	unsigned_char_str2 = (unsigned char *)str2;
	i = 0;
	while (unsigned_char_str1[i] && unsigned_char_str2[i]
		&& unsigned_char_str1[i] == unsigned_char_str2[i])
		i++;
	return (unsigned_char_str1[i] - unsigned_char_str2[i]);
}
