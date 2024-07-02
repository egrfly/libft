/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:16:27 by emflynn           #+#    #+#             */
/*   Updated: 2023/11/25 21:16:28 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_int_precision_error(t_options *options, int chars_before_zeros)
{
	if (options->precision_active \
			&& options->precision >= \
			(int64_t)INT_MAX - options->count - chars_before_zeros)
		options->error = true;
}

void	ft_set_float_precision_error(t_options *options,
			int chars_before_decimal_places, int chars_after_decimal_places)
{
	if (options->precision >= \
			(int64_t)INT_MAX - options->count - \
			chars_before_decimal_places - chars_after_decimal_places)
		options->error = true;
}

void	ft_set_float_precision_before_rounding(t_options *options)
{
	if (!options->precision_active)
		options->precision = 6;
	if (options->conversion == 'g')
		options->precision = ft_max(options->precision, 1);
}
