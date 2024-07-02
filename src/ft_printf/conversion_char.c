/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:45:55 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 21:06:21 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_char(t_options *options, char c)
{
	int	char_length;
	int	chars_before_zeros;

	char_length = 1;
	chars_before_zeros = 0;
	ft_prepend_spaces(options, chars_before_zeros, char_length);
	ft_prepend_zeros(options, chars_before_zeros, char_length);
	ft_putchar_buffered(options, c);
	ft_append_spaces(options, chars_before_zeros, char_length);
}

void	ft_convert_wchar(t_options *options, wchar_t c)
{
	int	char_length;
	int	chars_before_zeros;

	char_length = ft_wcharlen(c);
	chars_before_zeros = 0;
	if (!char_length)
		options->error = true;
	else
	{
		ft_prepend_spaces(options, chars_before_zeros, char_length);
		ft_prepend_zeros(options, chars_before_zeros, char_length);
		ft_putwchar(options, c);
		ft_append_spaces(options, chars_before_zeros, char_length);
	}
}
