/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:58:10 by emflynn           #+#    #+#             */
/*   Updated: 2025/02/24 18:36:18 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

static unsigned int	ft_count_splits(const char *str, const char *set)
{
	unsigned int	count;
	unsigned int	i;
	unsigned int	split_len;

	count = 0;
	i = 0;
	while (str[i])
	{
		split_len = ft_strcspn(&str[i], set);
		if (split_len > 0)
			count++;
		i += split_len + ft_strspn(&str[i + split_len], set);
	}
	return (count);
}

static void	ft_assign_splits(char ***splits, const char *str, const char *set)
{
	unsigned int	count;
	unsigned int	i;
	unsigned int	split_len;

	count = 0;
	i = 0;
	while (str[i])
	{
		split_len = ft_strcspn(&str[i], set);
		if (split_len > 0)
		{
			(*splits)[count] = ft_strndup(&str[i], split_len);
			if (!(*splits)[count])
			{
				ft_split_destroy(splits);
				return ;
			}
			count++;
		}
		i += split_len + ft_strspn(&str[i + split_len], set);
	}
	(*splits)[count] = NULL;
}

char	**ft_split(const char *str, const char *set)
{
	char	**splits;

	splits = malloc(sizeof(char *) * (ft_count_splits(str, set) + 1));
	if (!splits)
		return (NULL);
	ft_assign_splits(&splits, str, set);
	return (splits);
}
