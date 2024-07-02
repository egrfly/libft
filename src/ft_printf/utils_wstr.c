/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:17:19 by emflynn           #+#    #+#             */
/*   Updated: 2023/11/25 21:17:20 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_wstrlen(wchar_t *wstr)
{
	int	str_length;
	int	char_length;

	str_length = 0;
	while (*wstr)
	{
		char_length = ft_wcharlen(*wstr++);
		if (!char_length)
			return (-1);
		str_length += char_length;
	}
	return (str_length);
}

int	ft_wstrlen_capped(wchar_t *wstr, int cap)
{
	int	str_length;
	int	char_length;

	str_length = 0;
	if (!cap)
		return (0);
	while (*wstr)
	{
		char_length = ft_wcharlen(*wstr++);
		if (!char_length)
			return (-1);
		if (str_length + char_length > cap)
			break ;
		str_length += char_length;
	}
	return (str_length);
}

void	ft_putwstr_capped(t_options *options, wchar_t *wstr, int cap)
{
	int	str_length;
	int	char_length;

	str_length = 0;
	if (!cap)
		return ;
	while (*wstr)
	{
		char_length = ft_wcharlen(*wstr);
		if (!char_length || str_length + char_length > cap)
			break ;
		ft_putwchar(options, *wstr++);
		str_length += char_length;
	}
}
