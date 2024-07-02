/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_affixing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:47:25 by emflynn           #+#    #+#             */
/*   Updated: 2023/12/06 22:24:02 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prepend_spaces(t_options *options,
			int chars_before_zeros, int chars_after_zeros)
{
	int	num_spaces;

	if (options->flag_minus)
		return ;
	num_spaces = ft_spaces_length(options,
			chars_before_zeros, chars_after_zeros);
	ft_putchars(options, ' ', num_spaces);
}

void	ft_prepend_sign(t_options *options, bool is_negative)
{
	if (is_negative)
		ft_putchar_buffered(options, '-');
	else if (options->flag_plus)
		ft_putchar_buffered(options, '+');
	else if (options->flag_space)
		ft_putchar_buffered(options, ' ');
}

void	ft_prepend_base_prefix(t_options *options, bool nonzero_value)
{
	if (ft_strchr("pa", options->conversion) \
			|| (options->conversion == 'x' \
				&& options->flag_hash \
				&& nonzero_value))
		ft_putstr_case(options, "0x");
	else if (options->conversion == 'o' \
			&& options->flag_hash \
			&& (nonzero_value \
				|| (options->precision_active && !options->precision)))
		ft_putstr_buffered(options, "0");
	else if (options->conversion == 'b' && options->flag_hash && nonzero_value)
		ft_putstr_case(options, "0b");
}

void	ft_prepend_zeros(t_options *options,
			int chars_before_zeros, int chars_after_zeros)
{
	int	num_zeros;

	num_zeros = ft_zeros_length(options, chars_before_zeros, chars_after_zeros);
	ft_putchars(options, '0', num_zeros);
}

void	ft_append_spaces(t_options *options,
			int chars_before_zeros, int chars_after_zeros)
{
	int	num_spaces;

	if (!options->flag_minus)
		return ;
	num_spaces = ft_spaces_length(options,
			chars_before_zeros, chars_after_zeros);
	ft_putchars(options, ' ', num_spaces);
}
