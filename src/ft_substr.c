/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:46:27 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 18:03:22 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_substr(const char *str, unsigned int start, size_t n)
{
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	return (ft_strndup(&str[start], n));
}
