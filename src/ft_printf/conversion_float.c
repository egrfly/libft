/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:46:00 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/22 18:22:08 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_float_nonfinite(t_options *options, t_float_b2 *nbr_b2)
{
	char	*nonfinite_str;
	int		sign_length;
	int		nonfinite_str_length;

	options->flag_zero = false;
	if (nbr_b2->parts.coefficient & ~C_BIT_FIRST)
	{
		nonfinite_str = C_NAN_STR;
		if (MACOS)
			sign_length = 0;
		else
			sign_length = ft_sign_length(options, nbr_b2->parts.sign);
	}
	else
	{
		nonfinite_str = C_INF_STR;
		sign_length = ft_sign_length(options, nbr_b2->parts.sign);
	}
	nonfinite_str_length = ft_strlen(nonfinite_str);
	ft_prepend_spaces(options, sign_length, nonfinite_str_length);
	if (sign_length)
		ft_prepend_sign(options, nbr_b2->parts.sign);
	ft_putstr_case(options, nonfinite_str);
	ft_append_spaces(options, sign_length, nonfinite_str_length);
}

void	ft_convert_float_scientific(t_options *options,
			t_float_b10 *nbr_b10, char *float_buffer)
{
	int	sign_length;
	int	point_length;
	int	nbr_length;
	int	nonzero_decimal_places;
	int	exponent_length;

	sign_length = ft_sign_length(options, nbr_b10->sign);
	point_length = (options->precision || options->flag_hash);
	nbr_length = 1 + point_length + options->precision;
	nonzero_decimal_places = ft_min(options->precision, nbr_b10->length - 1);
	exponent_length = ft_max(ft_nbrlen_base(ft_abs(nbr_b10->exponent), 10), 2) + 2;
	ft_set_float_precision_error(options, sign_length + 1 + point_length,
		exponent_length);
	if (options->error)
		return ;
	ft_prepend_spaces(options, sign_length, nbr_length + exponent_length);
	ft_prepend_sign(options, nbr_b10->sign);
	ft_prepend_zeros(options, sign_length, nbr_length + exponent_length);
	ft_putnbr_capped(options, float_buffer, 1);
	ft_putchars(options, '.', point_length);
	ft_putnbr_capped(options, float_buffer + 1, nonzero_decimal_places);
	ft_putchars(options, '0', options->precision - nonzero_decimal_places);
	ft_putchar_case(options, 'e');
	options->count += ft_dprintf(options->fd, "%+.2d", nbr_b10->exponent);
	ft_append_spaces(options, sign_length, nbr_length + exponent_length);
}

static void	ft_convert_float_extended_decimal_only(t_options *options,
				t_float_b10 *nbr_b10, char *float_buffer)
{
	int	sign_length;
	int	point_length;
	int	nbr_length;
	int	zero_decimal_places;
	int	nonzero_decimal_places;

	sign_length = ft_sign_length(options, nbr_b10->sign);
	point_length = (options->precision || options->flag_hash);
	nbr_length = 1 + point_length + options->precision;
	zero_decimal_places = ft_min(options->precision, -nbr_b10->exponent - 1);
	nonzero_decimal_places = ft_min(options->precision - zero_decimal_places, \
		nbr_b10->length);
	ft_set_float_precision_error(options, sign_length + 1 + point_length, 0);
	if (options->error)
		return ;
	ft_prepend_spaces(options, sign_length, nbr_length);
	ft_prepend_sign(options, nbr_b10->sign);
	ft_prepend_zeros(options, sign_length, nbr_length);
	ft_putchar_buffered(options, '0');
	ft_putchars(options, '.', point_length);
	ft_putchars(options, '0', zero_decimal_places);
	ft_putnbr_capped(options, float_buffer, nonzero_decimal_places);
	ft_putchars(options, '0', options->precision
		- zero_decimal_places - nonzero_decimal_places);
	ft_append_spaces(options, sign_length, nbr_length);
}

static void	ft_convert_float_extended_integer_and_decimal(t_options *options,
				t_float_b10 *nbr_b10, char *float_buffer)
{
	int	sign_length;
	int	point_length;
	int	integer_part_length;
	int	nonzero_decimal_places;
	int	nbr_length;

	sign_length = ft_sign_length(options, nbr_b10->sign);
	point_length = (options->precision || options->flag_hash);
	integer_part_length = nbr_b10->exponent + 1;
	nbr_length = integer_part_length + point_length + options->precision;
	nonzero_decimal_places = ft_min(options->precision, \
		nbr_b10->length - integer_part_length);
	ft_set_float_precision_error(options,
		sign_length + integer_part_length + point_length, 0);
	if (options->error)
		return ;
	ft_prepend_spaces(options, sign_length, nbr_length);
	ft_prepend_sign(options, nbr_b10->sign);
	ft_prepend_zeros(options, sign_length, nbr_length);
	ft_putnbr_capped(options, float_buffer, integer_part_length);
	ft_putchars(options, '.', point_length);
	ft_putnbr_capped(options, float_buffer + integer_part_length, \
		nonzero_decimal_places);
	ft_putchars(options, '0', options->precision - nonzero_decimal_places);
	ft_append_spaces(options, sign_length, nbr_length);
}

void	ft_convert_float_extended(t_options *options,
			t_float_b10 *nbr_b10, char *float_buffer)
{
	if (!nbr_b10->integer_part && nbr_b10->decimal_part)
		ft_convert_float_extended_decimal_only(options,
			nbr_b10, float_buffer);
	else
		ft_convert_float_extended_integer_and_decimal(options,
			nbr_b10, float_buffer);
}
