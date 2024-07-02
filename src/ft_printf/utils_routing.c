/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:16:51 by emflynn           #+#    #+#             */
/*   Updated: 2023/11/25 21:16:52 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_route_float_conversion_scientific_or_extended(t_options *options,
			t_float_b10 *nbr_b10, char *float_buffer,
			int precision_before_rounding)
{
	if (nbr_b10->exponent < -4
		|| nbr_b10->exponent >= precision_before_rounding)
	{
		options->precision = ft_max(options->precision - 1, 0);
		ft_convert_float_scientific(options, nbr_b10, float_buffer);
	}
	else
	{
		options->precision = ft_max(options->precision - 1
				- nbr_b10->exponent, 0);
		ft_convert_float_extended(options, nbr_b10, float_buffer);
	}
}
