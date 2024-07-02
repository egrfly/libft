/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:49:02 by emflynn           #+#    #+#             */
/*   Updated: 2023/11/24 23:49:04 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint64_t	ft_shift_left_and_back(uint64_t nbr, int length)
{
	if (length >= C_BITS_UINT64_T)
		return (0);
	else if (length <= 0)
		return (nbr);
	else
		return ((nbr << length) >> length);
}

uint64_t	ft_shift_right(uint64_t nbr, int length)
{
	if (length >= C_BITS_UINT64_T)
		return (0);
	else if (length <= 0)
		return (nbr);
	else
		return (nbr >> length);
}
