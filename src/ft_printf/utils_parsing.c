/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:49:43 by emflynn           #+#    #+#             */
/*   Updated: 2023/11/24 23:49:44 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_flag(t_options *options, char c)
{
	if (c == '-')
		options->flag_minus = true;
	else if (c == '+')
		options->flag_plus = true;
	else if (c == '0')
		options->flag_zero = true;
	else if (c == ' ')
		options->flag_space = true;
	else if (c == '#')
		options->flag_hash = true;
}

int	ft_set_width(t_options *options, const char *str)
{
	int		i;
	int64_t	width;

	i = 0;
	width = 0;
	if (str[i] == '*')
	{
		width = va_arg(options->arg, int);
		if (width < 0)
		{
			options->flag_minus = true;
			width = -width;
		}
		i++;
	}
	else
		while (ft_strchr(C_WIDTH_PRECISION, str[i]))
			width = 10 * width + (str[i++] - '0');
	options->width = width;
	options->width_active = (options->width > 0);
	options->width_error = (width >= (int64_t)INT_MAX - options->count);
	return (i);
}

int	ft_set_precision(t_options *options, const char *str)
{
	int		i;
	int64_t	precision;

	i = 1;
	precision = 0;
	if (str[i] == '*')
	{
		precision = va_arg(options->arg, int);
		i++;
	}
	else
		while (ft_strchr(C_WIDTH_PRECISION, str[i]))
			precision = 10 * precision + (str[i++] - '0');
	options->precision = precision;
	options->precision_active = (options->precision >= 0);
	return (i);
}

void	ft_set_length(t_options *options, char c)
{
	if (c == 'l')
	{
		options->length_lcount++;
		options->length_ll = (options->length_lcount == 2);
		options->length_l = true;
	}
	else if (c == 'h')
	{
		options->length_hcount++;
		options->length_hh = (options->length_hcount == 2);
		options->length_h = true;
	}
	else if (c == 'L')
		options->length_lcap = true;
	else if (c == 'j')
		options->length_j = true;
	else if (c == 't')
		options->length_t = true;
	else if (c == 'z')
		options->length_z = true;
}
