/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_formatting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:48:13 by emflynn           #+#    #+#             */
/*   Updated: 2023/12/06 22:24:54 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_flags(t_options *options, const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(C_OPTIONS, str[i]))
	{
		if (ft_strchr(C_FLAGS, str[i]))
			ft_set_flag(options, str[i++]);
		else if (str[i] == '*' || ft_strchr(C_WIDTH_PRECISION, str[i]))
			i += ft_set_width(options, str + i);
		else if (str[i] == '.')
			i += ft_set_precision(options, str + i);
		else if (ft_strchr(C_LENGTH, str[i]))
			ft_set_length(options, str[i++]);
		else
			i++;
	}
	if (options->width_error)
		options->error = true;
	return (i);
}

void	ft_parse_conversion(t_options *options, char conversion)
{
	if (ft_strchr("XEFGA", conversion) || (conversion == 'B' && BINARY_MODE))
	{
		options->caps = true;
		options->conversion = ft_tolower(conversion);
	}
	else if (ft_strchr("CSDOU", conversion))
	{
		options->length_l = true;
		options->length_ll = false;
		options->length_h = false;
		options->length_hh = false;
		options->conversion = ft_tolower(conversion);
	}
	else
		options->conversion = conversion;
	if (ft_strchr("pxa", options->conversion))
		options->base = C_HEXADECIMAL_BASE;
	else if (ft_strchr("diuefg", options->conversion))
		options->base = C_DECIMAL_BASE;
	else if (options->conversion == 'o')
		options->base = C_OCTAL_BASE;
	else if (options->conversion == 'b' && BINARY_MODE)
		options->base = C_BINARY_BASE;
}

void	ft_route_conversion(t_options *options)
{
	if (options->conversion == 'c')
		ft_route_char_conversion(options, ft_get_char_arg(options));
	else if (options->conversion == 's')
		ft_route_str_conversion(options, ft_get_ptr_arg(options));
	else if (options->conversion == 'p')
		ft_route_uint_conversion(options, ft_get_ptr_arg(options));
	else if (ft_strchr("di", options->conversion))
		ft_route_int_conversion(options, ft_get_int_arg(options));
	else if (ft_strchr("oux", options->conversion))
		ft_route_uint_conversion(options, ft_get_uint_arg(options));
	else if (options->conversion == 'b' && BINARY_MODE)
		ft_route_uint_conversion(options, ft_get_uint_arg(options));
	else if (ft_strchr("efga", options->conversion))
		ft_route_float_conversion(options, ft_get_float_arg(options));
	else if (options->conversion == 'n')
		ft_save_count(options, ft_get_ptr_arg(options));
	else if (options->conversion && MACOS)
		ft_route_char_conversion(options, options->conversion);
	else if (options->conversion == '%')
	{
		ft_reset_options(options);
		ft_route_char_conversion(options, '%');
	}
	else
		options->conversion_recognised = false;
}

void	ft_put_formatted_str(const char *str, t_options *options)
{
	char	*conversion_start;

	while (*str && !options->error)
	{
		ft_reset_options(options);
		while (*str && *str != '%')
			ft_putchar_buffered(options, *str++);
		if (*str == '%')
		{
			conversion_start = (char *)str;
			str++;
		}
		else
			break ;
		str += ft_parse_flags(options, str);
		ft_parse_conversion(options, *str);
		if (!*str || options->error)
			break ;
		str++;
		ft_route_conversion(options);
		if (!options->conversion_recognised)
			ft_putstr_capped(options, conversion_start, str - conversion_start);
		if (!options->error)
			ft_flush(options);
	}
}
