/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:46:32 by emflynn           #+#    #+#             */
/*   Updated: 2023/12/06 22:22:41 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_int(t_options *options, int64_t value)
{
	uint64_t	unsigned_value;
	int			sign_length;
	int			nbr_length;
	bool		is_negative;
	int			zero_value_zero_precision;

	is_negative = value < 0;
	zero_value_zero_precision = (options->precision_active
			&& !options->precision
			&& !value);
	sign_length = ft_sign_length(options, is_negative);
	unsigned_value = ft_abs(value);
	nbr_length = ft_nbrlen(unsigned_value, options->base);
	if (zero_value_zero_precision)
		nbr_length = 0;
	ft_set_int_precision_error(options, sign_length);
	if (options->error)
		return ;
	ft_prepend_spaces(options, sign_length, nbr_length);
	ft_prepend_sign(options, is_negative);
	ft_prepend_zeros(options, sign_length, nbr_length);
	if (!zero_value_zero_precision)
		ft_putnbr_buffered(options, unsigned_value);
	ft_append_spaces(options, sign_length, nbr_length);
}
