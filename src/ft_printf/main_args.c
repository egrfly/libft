/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:47:56 by emflynn           #+#    #+#             */
/*   Updated: 2023/11/24 23:47:57 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	ft_get_char_arg(t_options *options)
{
	if (options->length_l)
		return ((wchar_t)va_arg(options->arg, wint_t));
	else
		return ((char)va_arg(options->arg, int));
}

uintptr_t	ft_get_ptr_arg(t_options *options)
{
	return ((uintptr_t)va_arg(options->arg, void *));
}

int64_t	ft_get_int_arg(t_options *options)
{
	if (options->length_ll)
		return (va_arg(options->arg, long long));
	else if (options->length_l)
		return (va_arg(options->arg, long));
	else if (options->length_j)
		return (va_arg(options->arg, intmax_t));
	else if (options->length_z)
		return (va_arg(options->arg, ssize_t));
	else if (options->length_t)
		return (va_arg(options->arg, ptrdiff_t));
	else if (options->length_hh)
		return ((signed char)va_arg(options->arg, int));
	else if (options->length_h)
		return ((short)va_arg(options->arg, int));
	else
		return (va_arg(options->arg, int));
}

uint64_t	ft_get_uint_arg(t_options *options)
{
	if (options->length_ll)
		return (va_arg(options->arg, unsigned long long));
	else if (options->length_l)
		return (va_arg(options->arg, unsigned long));
	else if (options->length_j)
		return (va_arg(options->arg, uintmax_t));
	else if (options->length_z)
		return (va_arg(options->arg, size_t));
	else if (options->length_t && sizeof(ptrdiff_t) == 4)
		return (va_arg(options->arg, uint32_t));
	else if (options->length_t)
		return (va_arg(options->arg, uint64_t));
	else if (options->length_hh)
		return ((unsigned char)va_arg(options->arg, unsigned int));
	else if (options->length_h)
		return ((unsigned short)va_arg(options->arg, unsigned int));
	else
		return (va_arg(options->arg, unsigned int));
}

long double	ft_get_float_arg(t_options *options)
{
	if (options->length_lcap)
		return (va_arg(options->arg, long double));
	else
		return (va_arg(options->arg, double));
}
