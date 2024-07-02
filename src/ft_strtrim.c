/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:49:05 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 18:00:54 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strtrim(const char *str, const char *set)
{
	unsigned int	head_len;
	unsigned int	trim_len;

	head_len = ft_strspn(str, set);
	trim_len = ft_strlen(&str[head_len]);
	if (trim_len == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, str[head_len + trim_len - 1]))
		trim_len--;
	return (ft_strndup(&str[head_len], trim_len));
}
