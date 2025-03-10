/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:16:37 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/10 11:15:37 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_buffered(t_options *options, char c)
{
	static char	buffer[C_BUFFER_SIZE];
	static int	pos = 0;
	ssize_t		chars_written;

	if (pos == C_BUFFER_SIZE || options->flush)
	{
		if (pos && !options->error)
		{
			chars_written = write(options->fd, buffer, pos);
			pos = 0;
			if (chars_written < 0)
			{
				options->error = true;
				return ;
			}
		}
		if (options->flush)
		{
			options->flush = 0;
			return ;
		}
	}
	buffer[pos++] = c;
	options->count++;
}

void	ft_putchar_case(t_options *options, char c)
{
	if (options->caps && ft_islower(c))
		ft_putchar_buffered(options, ft_toupper(c));
	else if (!options->caps && ft_isupper(c))
		ft_putchar_buffered(options, ft_tolower(c));
	else
		ft_putchar_buffered(options, c);
}

void	ft_putchars(t_options *options, char c, int length)
{
	int	i;

	i = 0;
	while (i++ < length)
		ft_putchar_buffered(options, c);
}

void	ft_flush(t_options *options)
{
	options->flush = 1;
	ft_putchar_buffered(options, 0);
}
