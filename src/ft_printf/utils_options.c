/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:49:36 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 21:09:21 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialise_options(t_options *options, int fd)
{
	options->count = 0;
	options->error = false;
	options->fd = fd;
	options->flush = false;
}

void	ft_reset_options(t_options *options)
{
	options->conversion = '\0';
	options->conversion_recognised = true;
	options->caps = false;
	options->base = 0;
	options->flag_minus = false;
	options->flag_zero = false;
	options->flag_space = false;
	options->flag_plus = false;
	options->flag_hash = false;
	options->width = 0;
	options->width_active = false;
	options->width_error = false;
	options->precision = 0;
	options->precision_active = false;
	options->length_l = false;
	options->length_ll = false;
	options->length_h = false;
	options->length_hh = false;
	options->length_lcap = false;
	options->length_j = false;
	options->length_t = false;
	options->length_z = false;
	options->length_lcount = 0;
	options->length_hcount = 0;
}
