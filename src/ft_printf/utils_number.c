/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:49:18 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/22 18:59:38 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_buffered(t_options *options, uint64_t nbr)
{
	uint64_t	quotient;
	uint64_t	remainder;

	quotient = nbr / options->base;
	remainder = nbr % options->base;
	if (quotient)
		ft_putnbr_buffered(options, quotient);
	ft_putchar_case(options, C_DIGITS[remainder]);
}

void	ft_putnbr_capped(t_options *options, char *buffer, int cap)
{
	int	i;

	i = 0;
	while (i < cap)
		ft_putchar_case(options, C_DIGITS[(int)buffer[i++]]);
}

int	ft_uint_to_buffer(uint64_t nbr, char *buffer, int base)
{
	int	i;
	int	significant_digit_count;
	int	remainder;

	significant_digit_count = 0;
	i = ft_nbrlen_base(nbr, base);
	while (i--)
	{
		remainder = nbr % base;
		buffer[i] = remainder;
		significant_digit_count += (significant_digit_count || remainder);
		nbr /= base;
	}
	return (significant_digit_count);
}

int	ft_uint_to_buffer_from_right(uint64_t nbr, char *buffer, int base,
		int offset)
{
	int	i;
	int	significant_digit_count;
	int	remainder;

	significant_digit_count = 0;
	i = offset;
	while (i--)
	{
		remainder = nbr % base;
		buffer[i] = remainder;
		significant_digit_count += (significant_digit_count || remainder);
		nbr /= base;
	}
	return (significant_digit_count);
}
