/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:17:13 by emflynn           #+#    #+#             */
/*   Updated: 2023/12/06 22:21:05 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_wcharlen_utf8(wchar_t c)
{
	if (0 <= c && c < 0x80)
		return (1);
	else if (0x80 <= c && c < 0x800)
		return (2);
	else if (0x800 <= c && c < 0x10000 && !(0xD800 <= c && c < 0xE000))
		return (3);
	else if (0x10000 <= c && c < 0x110000)
		return (4);
	else
		return (0);
}

static void	ft_putwchar_utf8(t_options *options, wchar_t c)
{
	if (0 <= c && c < 0x80)
		ft_putchar_buffered(options, c);
	else if (0x80 <= c && c < 0x800)
	{
		ft_putchar_buffered(options, C_BIT_UTF8_2 + ((c >> 6) & C_BIT_LAST_6));
		ft_putchar_buffered(options, C_BIT_UTF8_1 + (c & C_BIT_LAST_6));
	}
	else if (0x800 <= c && c < 0x10000 && !(0xD800 <= c && c < 0xE000))
	{
		ft_putchar_buffered(options, C_BIT_UTF8_3 + ((c >> 12) & C_BIT_LAST_6));
		ft_putchar_buffered(options, C_BIT_UTF8_1 + ((c >> 6) & C_BIT_LAST_6));
		ft_putchar_buffered(options, C_BIT_UTF8_1 + (c & C_BIT_LAST_6));
	}
	else if (0x10000 <= c && c < 0x110000)
	{
		ft_putchar_buffered(options, C_BIT_UTF8_4 + ((c >> 18) & C_BIT_LAST_6));
		ft_putchar_buffered(options, C_BIT_UTF8_1 + ((c >> 12) & C_BIT_LAST_6));
		ft_putchar_buffered(options, C_BIT_UTF8_1 + ((c >> 6) & C_BIT_LAST_6));
		ft_putchar_buffered(options, C_BIT_UTF8_1 + (c & C_BIT_LAST_6));
	}
}

int	ft_wcharlen(wchar_t c)
{
	if (UTF8)
		return (ft_wcharlen_utf8(c));
	else if (0 <= c && c < 256)
		return (1);
	else
		return (0);
}

void	ft_putwchar(t_options *options, wchar_t c)
{
	if (UTF8)
		ft_putwchar_utf8(options, c);
	else if (0 <= c && c < 256)
		ft_putchar_buffered(options, c);
	else
		return ;
}
