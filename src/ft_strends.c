/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strends.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:52:26 by emflynn           #+#    #+#             */
/*   Updated: 2025/02/05 03:53:18 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "ft_string.h"

bool	ft_strends(const char *str, const char *suffix)
{
	size_t	str_len;
	size_t	suffix_len;

	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);
	if (suffix_len > str_len)
		return (false);
	return (ft_strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0);
}
