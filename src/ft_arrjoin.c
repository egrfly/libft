/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:26:34 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/11 01:34:02 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

static size_t	get_join_length(char **arr, const char *separator)
{
	size_t	total_length;
	size_t	separator_length;
	size_t	i;

	total_length = 0;
	separator_length = ft_strlen(separator);
	if (arr[0])
		total_length = ft_strlen(arr[0]);
	i = 1;
	while (arr[i])
	{
		total_length += separator_length;
		total_length += ft_strlen(arr[i]);
		i++;
	}
	return (total_length);
}

char	*ft_arrjoin(char **arr, const char *separator)
{
	char	*join;
	size_t	i;

	join = malloc(sizeof(char) * (get_join_length(arr, separator) + 1));
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
