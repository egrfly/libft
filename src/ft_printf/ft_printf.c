/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:47:14 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 21:11:25 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	t_options	options;

	if (!str)
		return (-1);
	ft_initialise_options(&options, STDOUT_FILENO);
	va_start(options.arg, str);
	ft_put_formatted_str(str, &options);
	va_end(options.arg);
	ft_flush(&options);
	if (options.error)
		return (-1);
	return (options.count);
}
