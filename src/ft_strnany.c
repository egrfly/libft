/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnany.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:09:28 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/08 06:13:22 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

bool	ft_strnany(const char *str, bool (*f)(char), size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i])
	{
		if (f(str[i]))
			return (true);
		i++;
	}
	return (false);
}
