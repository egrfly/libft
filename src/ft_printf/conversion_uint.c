/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_uint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:47:04 by emflynn           #+#    #+#             */
/*   Updated: 2023/12/06 22:22:41 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_uint(t_options *options, uint64_t value)
{
	int		base_prefix_length;
	int		nbr_length;
	bool	nonzero_value;
	bool	zero_value_zero_precision;

	nonzero_value = value != 0;
	zero_value_zero_precision = (options->precision_active
			&& !options->precision
			&& !value);
	base_prefix_length = ft_base_prefix_length(options, nonzero_value);
	nbr_length = ft_nbrlen(value, options->base);
	if (zero_value_zero_precision)
		nbr_length = 0;
	ft_set_int_precision_error(options, base_prefix_length);
	if (options->error)
		return ;
	ft_prepend_spaces(options, base_prefix_length, nbr_length);
	ft_prepend_base_prefix(options, nonzero_value);
	ft_prepend_zeros(options, base_prefix_length, nbr_length);
	if (!zero_value_zero_precision)
		ft_putnbr_buffered(options, value);
	ft_append_spaces(options, base_prefix_length, nbr_length);
}
