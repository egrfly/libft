/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:46:20 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/22 18:58:49 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_coefficient_and_exponent(t_options *options,
				t_float_b2 *nbr_b2, uint64_t *coefficient,
				int *unbiased_exponent)
{
	uint64_t	rounding_digit;

	*coefficient = nbr_b2->parts.coefficient;
	if (nbr_b2->parts.coefficient)
		*unbiased_exponent = nbr_b2->parts.exponent - C_EXPONENT_BIAS
			+ !nbr_b2->parts.exponent;
	else
		*unbiased_exponent = 0;
	while (*coefficient && !(C_BIT_FIRST & *coefficient))
	{
		*coefficient <<= 1;
		(*unbiased_exponent)--;
	}
	if (options->precision_active && options->precision < 16)
	{
		*coefficient >>= 1;
		rounding_digit = C_BIT_SECOND
			>> (C_HEXADECIMAL_BASE / C_BINARY_BASE * options->precision + 1);
		*coefficient += (rounding_digit & *coefficient) << 1;
		if (C_BIT_FIRST & *coefficient)
			(*unbiased_exponent)++;
		else
			*coefficient <<= 1;
	}
}

static void	ft_fill_float_buffer_and_set_precision(t_options *options,
				char *float_buffer, uint64_t coefficient)
{
	uint64_t	fractional_part;
	int			fractional_part_length;

	if (coefficient)
		float_buffer[0] = 1;
	else
		float_buffer[0] = 0;
	fractional_part = coefficient << 1;
	fractional_part_length = ft_uint_to_buffer_from_right(
			fractional_part,
			float_buffer + 1, 16, 16);
	if (!options->precision_active)
		options->precision = fractional_part_length;
}

static void	ft_measure_prefix_and_point(t_options *options,
				t_float_b2 *nbr_b2, int *prefix_length, int *point_length)
{
	*prefix_length = ft_sign_length(options, nbr_b2->parts.sign)
		+ ft_base_prefix_length(options, nbr_b2->parts.coefficient);
	*point_length = (options->precision || options->flag_hash);
}

static void	ft_set_nbr_with_exponent_length_and_float_precision_error(
				t_options *options, t_float_b2 *nbr_b2,
				int exponent, int *nbr_with_exponent_length)
{
	int	prefix_length;
	int	point_length;
	int	suffix_length;

	ft_measure_prefix_and_point(options, nbr_b2, &prefix_length, &point_length);
	suffix_length = 2 + ft_nbrlen_base(ft_abs(exponent), 10);
	*nbr_with_exponent_length = 1 + point_length + options->precision
		+ suffix_length;
	ft_set_float_precision_error(options, prefix_length + 1 + point_length,
		suffix_length);
}

void	ft_convert_float_hexadecimal(t_options *options,
			t_float_b2 *nbr_b2, char *float_buffer)
{
	uint64_t	coefficient;
	int			exponent;
	int			prefix_length;
	int			point_length;
	int			nbr_with_exponent_length;

	ft_set_coefficient_and_exponent(options, nbr_b2, &coefficient, &exponent);
	ft_fill_float_buffer_and_set_precision(options, float_buffer, coefficient);
	ft_measure_prefix_and_point(options, nbr_b2, &prefix_length, &point_length);
	ft_set_nbr_with_exponent_length_and_float_precision_error(options, nbr_b2,
		exponent, &nbr_with_exponent_length);
	if (options->error)
		return ;
	ft_prepend_spaces(options, prefix_length, nbr_with_exponent_length);
	ft_prepend_sign(options, nbr_b2->parts.sign);
	ft_prepend_base_prefix(options, nbr_b2->parts.coefficient);
	ft_prepend_zeros(options, prefix_length, nbr_with_exponent_length);
	ft_putnbr_capped(options, float_buffer, 1);
	ft_putchars(options, '.', point_length);
	ft_putnbr_capped(options, float_buffer + 1, ft_min(options->precision, 16));
	ft_putchars(options, '0', ft_max(0, options->precision - 16));
	ft_putchar_case(options, 'p');
	options->count += ft_dprintf(options->fd, "%+d", exponent);
	ft_append_spaces(options, prefix_length, nbr_with_exponent_length);
}
