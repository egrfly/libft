/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 08:50:58 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:48:06 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	i;

	map = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (str[i])
	{
		map[i] = f(i, str[i]);
		i++;
	}
	map[i] = '\0';
	return (map);
}
