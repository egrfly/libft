/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_routing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:48:27 by emflynn           #+#    #+#             */
/*   Updated: 2023/11/28 15:38:17 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_route_char_conversion(t_options *options, wchar_t c)
{
	if (options->length_l)
		ft_convert_wchar(options, (wchar_t)c);
	else
		ft_convert_char(options, (char)c);
}

void	ft_route_str_conversion(t_options *options, uintptr_t ptr)
{
	if (options->length_l)
		ft_convert_wstr(options, (wchar_t *)ptr);
	else
		ft_convert_str(options, (char *)ptr);
}

void	ft_route_int_conversion(t_options *options, int64_t value)
{
	ft_convert_int(options, value);
}

void	ft_route_uint_conversion(t_options *options, uint64_t value)
{
	if (options->conversion == 'p' && value == 0 && !MACOS)
	{
		options->precision_active = false;
		ft_convert_str(options, C_NIL_STR);
	}
	else
		ft_convert_uint(options, value);
}

void	ft_route_float_conversion(t_options *options, long double value)
{
	char		float_buffer[C_MAX_FLOAT_DIGITS];
	t_float_b2	nbr_b2;
	t_float_b10	nbr_b10;
	int			precision_before_rounding;

	nbr_b2.value = value;
	if (nbr_b2.parts.exponent == C_BIT_NONFINITE_EXPONENT)
		ft_convert_float_nonfinite(options, &nbr_b2);
	else if (options->conversion == 'a')
		ft_convert_float_hexadecimal(options, &nbr_b2, float_buffer);
	else
	{
		ft_float_to_buffer(&nbr_b2, &nbr_b10, float_buffer);
		ft_set_float_precision_before_rounding(options);
		precision_before_rounding = options->precision;
		ft_round_b10(options, &nbr_b10, float_buffer);
		if (options->conversion == 'e')
			ft_convert_float_scientific(options, &nbr_b10, float_buffer);
		else if (options->conversion == 'f')
			ft_convert_float_extended(options, &nbr_b10, float_buffer);
		else if (options->conversion == 'g')
			ft_route_float_conversion_scientific_or_extended(options, &nbr_b10,
				float_buffer, precision_before_rounding);
	}
}
