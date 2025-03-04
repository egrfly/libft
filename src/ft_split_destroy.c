/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:58:10 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/04 02:59:11 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_split_destroy(char ***splits)
{
	unsigned int	i;

	i = 0;
	while ((*splits)[i])
	{
		free((*splits)[i]);
		i++;
	}
	free(*splits);
	*splits = NULL;
}
