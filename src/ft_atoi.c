/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:53:17 by emflynn           #+#    #+#             */
/*   Updated: 2025/02/18 00:00:22 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_ctype.h"
#include "ft_defs.h"
#include "ft_string.h"

bool	ft_atoi(const char *nstr, int *n)
{
	int		multiplier;
	bool	has_digits;

	*n = 0;
	multiplier = 1;
	has_digits = false;
	nstr += ft_strspn(nstr, WHITESPACE);
	if (*nstr == '+' || *nstr == '-')
	{
		if (*nstr == '-')
			multiplier = -1;
		nstr++;
	}
	while (ft_isdigit(*nstr))
	{
		has_digits = true;
		*n = *n * 10 + *nstr - '0';
		if (*n != (*n - (*nstr - '0')) / 10)
			return (false);
		nstr++;
	}
	nstr += ft_strspn(nstr, WHITESPACE);
	*n *= multiplier;
	return (!*nstr && has_digits);
}
