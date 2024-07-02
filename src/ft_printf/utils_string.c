/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:17:00 by emflynn           #+#    #+#             */
/*   Updated: 2023/12/06 22:24:54 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_capped(char *str, int cap)
{
	int	i;

	i = 0;
	while (i < cap && str[i])
		i++;
	return (i);
}

void	ft_putstr_buffered(t_options *options, char *str)
{
	while (*str)
		ft_putchar_buffered(options, *str++);
}

void	ft_putstr_capped(t_options *options, char *str, int cap)
{
	int	i;

	i = 0;
	while (i < cap && str[i])
		ft_putchar_buffered(options, str[i++]);
}

void	ft_putstr_case(t_options *options, char *str)
{
	while (*str)
		ft_putchar_case(options, *str++);
}
