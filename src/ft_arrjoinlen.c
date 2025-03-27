/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrjoinlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 11:04:04 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/22 11:04:23 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

size_t	ft_arrjoinlen(char **arr, const char *separator)
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
