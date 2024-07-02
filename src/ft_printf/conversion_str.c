/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:46:53 by emflynn           #+#    #+#             */
/*   Updated: 2023/12/06 22:25:17 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert_null_str(t_options *options)
{
	if (!options->precision_active
		|| options->precision >= (int)ft_strlen(C_NULL_STR)
		|| MACOS)
		ft_convert_str(options, C_NULL_STR);
	else
		ft_convert_str(options, C_EMPTY_STR);
}

void	ft_convert_str(t_options *options, char *str)
{
	int	chars_to_put;
	int	chars_before_zeros;

	if (!MACOS)
		options->flag_zero = false;
	if (!str)
		ft_convert_null_str(options);
	else
	{
		if (options->precision_active)
			chars_to_put = ft_strlen_capped(str, options->precision);
		else
			chars_to_put = ft_strlen(str);
		chars_before_zeros = 0;
		ft_prepend_spaces(options, chars_before_zeros, chars_to_put);
		ft_prepend_zeros(options, chars_before_zeros, chars_to_put);
		ft_putstr_capped(options, str, chars_to_put);
		ft_append_spaces(options, chars_before_zeros, chars_to_put);
	}
}

void	ft_convert_wstr(t_options *options, wchar_t *wstr)
{
	int	chars_to_put;
	int	chars_before_zeros;

	if (!MACOS)
		options->flag_zero = false;
	if (!wstr)
		ft_convert_null_str(options);
	else
	{
		if (options->precision_active)
			chars_to_put = ft_wstrlen_capped(wstr, options->precision);
		else
			chars_to_put = ft_wstrlen(wstr);
		if (chars_to_put < 0)
		{
			options->error = true;
			return ;
		}
		chars_before_zeros = 0;
		ft_prepend_spaces(options, chars_before_zeros, chars_to_put);
		ft_prepend_zeros(options, chars_before_zeros, chars_to_put);
		ft_putwstr_capped(options, wstr, chars_to_put);
		ft_append_spaces(options, chars_before_zeros, chars_to_put);
	}
}
