/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_saving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:48:36 by emflynn           #+#    #+#             */
/*   Updated: 2023/11/24 23:48:39 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_count(t_options *options, uintptr_t ptr)
{
	if (!ptr)
		return ;
	if (options->length_ll)
		*((long long *)ptr) = options->count;
	else if (options->length_l)
		*((long *)ptr) = (long)options->count;
	else if (options->length_j)
		*((intmax_t *)ptr) = (intmax_t)options->count;
	else if (options->length_z)
		*((ssize_t *)ptr) = (ssize_t)options->count;
	else if (options->length_t)
		*((ptrdiff_t *)ptr) = (ptrdiff_t)options->count;
	else if (options->length_hh)
		*((signed char *)ptr) = (signed char)options->count;
	else if (options->length_h)
		*((short *)ptr) = (short)options->count;
	else
		*((int *)ptr) = (int)options->count;
}
