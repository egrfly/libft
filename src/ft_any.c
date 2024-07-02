/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:09:28 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 16:21:22 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_any(const char *str, bool (*f)(char))
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (f(str[i]))
			return (true);
		i++;
	}
	return (false);
}
