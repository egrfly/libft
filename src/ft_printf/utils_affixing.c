/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_affixing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:48:50 by emflynn           #+#    #+#             */
/*   Updated: 2023/11/24 23:48:50 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_spaces_length(t_options *options,
		int chars_before_zeros, int chars_after_zeros)
{
	int	num_zeros;
	int	num_spaces;

	if (!options->width_active)
		return (0);
	num_zeros = ft_zeros_length(options, chars_before_zeros, chars_after_zeros);
	num_spaces = options->width - chars_before_zeros - num_zeros
		- chars_after_zeros;
	return (ft_max(num_spaces, 0));
}

int	ft_sign_length(t_options *options, bool is_negative)
{
	if (is_negative || options->flag_plus || options->flag_space)
		return (1);
	else
		return (0);
}

int	ft_base_prefix_length(t_options *options, bool nonzero_value)
{
	if (ft_strchr("pa", options->conversion) \
			|| (ft_strchr("xb", options->conversion) \
				&& options->flag_hash \
				&& nonzero_value))
		return (2);
	else if (options->conversion == 'o' \
			&& options->flag_hash \
			&& (nonzero_value \
				|| (options->precision_active && !options->precision)))
		return (1);
	return (0);
}

int	ft_zeros_length(t_options *options,
		int chars_before_zeros, int chars_after_zeros)
{
	int		num_zeros;
	bool	has_precision_zeros;
	int		extra_octal_zero;

	num_zeros = 0;
	has_precision_zeros = (bool)ft_strchr("pdiouxb", options->conversion);
	extra_octal_zero = (options->conversion == 'o' \
						&& options->flag_hash \
						&& chars_before_zeros > 0);
	if (options->precision_active && has_precision_zeros)
		num_zeros = options->precision - chars_after_zeros - extra_octal_zero;
	else if (options->width_active \
			&& options->flag_zero \
			&& !options->flag_minus)
		num_zeros = options->width - chars_before_zeros - chars_after_zeros;
	return (ft_max(num_zeros, 0));
}
