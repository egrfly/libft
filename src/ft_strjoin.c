/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:35:23 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:44:28 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*join;

	join = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!join)
		return (NULL);
	ft_strcpy(join, str1);
	ft_strcat(join, str2);
	return (join);
}
