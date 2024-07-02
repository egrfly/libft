/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:53:17 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/03 00:17:45 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include "ft_ctype.h"
#include "ft_defs.h"
#include "ft_string.h"

static bool	ft_would_surpass_limit(int n, int next_digit, bool is_negative)
{
	int	n_cutoff;
	int	next_digit_cutoff;

	if (is_negative)
	{
		n_cutoff = INT_MIN / 10;
		next_digit_cutoff = INT_MIN % 10;
		if (next_digit_cutoff > 0)
		{
			next_digit_cutoff -= 10;
			n_cutoff += 1;
		}
		n_cutoff = -n_cutoff;
		next_digit_cutoff = -next_digit_cutoff;
	}
	else
	{
		n_cutoff = INT_MAX / 10;
		next_digit_cutoff = INT_MAX % 10;
	}
	return (n > n_cutoff || (n == n_cutoff && next_digit > next_digit_cutoff));
}

bool	ft_atoi_strict(const char *nstr, int *n)
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
		if (ft_would_surpass_limit(*n, *nstr - '0', multiplier == -1))
			return (false);
		*n = *n * 10 + *nstr - '0';
		nstr++;
	}
	nstr += ft_strspn(nstr, WHITESPACE);
	*n *= multiplier;
	return (!*nstr && has_digits);
}
