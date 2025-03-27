/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:49:10 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/22 18:59:30 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_halve_b10(char *float_buffer, int *float_length,
				bool suppress_shift)
{
	int	i;
	int	unsuppressed_shift_distance;
	int	shift_distance;
	int	digit_to_carry;
	int	carried_digit;

	i = 0;
	while (float_buffer[i] == 0)
		i++;
	unsuppressed_shift_distance = (float_buffer[i] == 1);
	shift_distance = (unsuppressed_shift_distance && !suppress_shift);
	i -= !shift_distance;
	carried_digit = shift_distance * 5;
	while (++i < *float_length)
	{
		digit_to_carry = (float_buffer[i] % 2) * 5;
		float_buffer[i - shift_distance] = float_buffer[i] / 2 + carried_digit;
		carried_digit = digit_to_carry;
	}
	float_buffer[i - shift_distance] = carried_digit;
	if (shift_distance)
		(*float_length)--;
	if (carried_digit)
		(*float_length)++;
	return (unsuppressed_shift_distance);
}

static int	ft_double_b10(char *float_buffer, int *float_length)
{
	int	i;
	int	shift_distance;
	int	digit_to_carry;
	int	carried_digit;

	shift_distance = float_buffer[0] / 5;
	i = *float_length;
	carried_digit = 0;
	while (i--)
	{
		digit_to_carry = float_buffer[i] / 5;
		float_buffer[i + shift_distance] = (float_buffer[i] % 5) * 2
			+ carried_digit;
		carried_digit = digit_to_carry;
	}
	if (shift_distance)
	{
		float_buffer[0] = carried_digit;
		(*float_length)++;
	}
	return (shift_distance);
}

static void	ft_integer_part_to_buffer(t_float_b10 *nbr_b10,
				int unbiased_exponent_b2, char *float_buffer)
{
	ft_uint_to_buffer(nbr_b10->integer_part, float_buffer, 10);
	nbr_b10->length = ft_nbrlen_base(nbr_b10->integer_part, 10);
	while (unbiased_exponent_b2-- > C_BITS_UINT64_T - 1)
		nbr_b10->exponent += ft_double_b10(float_buffer, &(nbr_b10->length));
}

static void	ft_decimal_part_to_buffer(t_float_b10 *nbr_b10,
				int unbiased_exponent_b2, char *float_buffer)
{
	int		zero_tail_length;
	int		initial_length;
	int		length;
	int		shift_distance;
	bool	suppress_shift;

	zero_tail_length = 0;
	while (!(C_BIT_LAST & nbr_b10->decimal_part))
	{
		nbr_b10->decimal_part >>= 1;
		zero_tail_length++;
	}
	float_buffer += nbr_b10->length;
	initial_length = ft_uint_to_buffer(nbr_b10->decimal_part, float_buffer, 10);
	length = initial_length;
	shift_distance = 0;
	while (unbiased_exponent_b2++ < C_BITS_UINT64_T - zero_tail_length - 1)
	{
		suppress_shift = (nbr_b10->integer_part
				&& shift_distance >= initial_length);
		shift_distance += ft_halve_b10(float_buffer, &length, suppress_shift);
	}
	nbr_b10->length += length;
	if (!nbr_b10->integer_part)
		nbr_b10->exponent += (initial_length - shift_distance - 1);
}

void	ft_float_to_buffer(t_float_b2 *nbr_b2, t_float_b10 *nbr_b10,
			char *float_buffer)
{
	int	unbiased_exponent_b2;

	unbiased_exponent_b2 = nbr_b2->parts.exponent - C_EXPONENT_BIAS
		+ !nbr_b2->parts.exponent;
	nbr_b10->sign = nbr_b2->parts.sign;
	nbr_b10->integer_part = ft_shift_right(nbr_b2->parts.coefficient,
			C_BITS_UINT64_T - (unbiased_exponent_b2 + 1));
	nbr_b10->decimal_part = ft_shift_left_and_back(nbr_b2->parts.coefficient,
			unbiased_exponent_b2 + 1);
	nbr_b10->exponent = ft_nbrlen_base(nbr_b10->integer_part, 10) - 1;
	nbr_b10->length = 0;
	if (nbr_b10->integer_part)
		ft_integer_part_to_buffer(nbr_b10, unbiased_exponent_b2, float_buffer);
	if (nbr_b10->decimal_part)
		ft_decimal_part_to_buffer(nbr_b10, unbiased_exponent_b2, float_buffer);
	if (!nbr_b10->integer_part && !nbr_b10->decimal_part)
	{
		float_buffer[0] = 0;
		nbr_b10->length = 1;
	}
}
