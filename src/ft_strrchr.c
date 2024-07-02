/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 23:22:20 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:54:28 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *str, char c)
{
	char			*latest_occurrence;
	unsigned int	i;

	latest_occurrence = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			latest_occurrence = (char *)&str[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (latest_occurrence);
}
