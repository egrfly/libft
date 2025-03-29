/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:26:34 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/29 22:43:34 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stdlib.h"
#include "ft_string.h"

char	*ft_arrjoin(char **arr, const char *separator)
{
	char	*join;
	size_t	i;

	join = ft_calloc(ft_arrjoinlen(arr, separator) + 1, sizeof(char));
	if (!join)
		return (NULL);
	if (arr[0])
		ft_strcpy(join, arr[0]);
	i = 1;
	while (arr[i])
	{
		ft_strcat(join, separator);
		ft_strcat(join, arr[i]);
		i++;
	}
	return (join);
}
