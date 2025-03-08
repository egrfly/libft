/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strntoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:53:17 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/08 06:03:46 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ft_ctype.h"
#include "ft_defs.h"
#include "ft_string.h"

static bool	would_surpass_limit(int nbr, int next_digit, bool is_negative)
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
	return (nbr > n_cutoff || (nbr == n_cutoff && next_digit > next_digit_cutoff));
}

bool	ft_strntoi(const char *nbr_str, int *nbr, size_t n)
{
	int		multiplier;
	bool	has_digits;
	size_t	i;

	*nbr = 0;
	multiplier = 1;
	has_digits = false;
	i = ft_strspn(nbr_str, WHITESPACE);
	if (i < n && (nbr_str[i] == '+' || nbr_str[i] == '-'))
	{
		if (nbr_str[i] == '-')
			multiplier = -1;
		i++;
	}
	while (i < n && ft_isdigit(nbr_str[i]))
	{
		has_digits = true;
		if (would_surpass_limit(*nbr, nbr_str[i] - '0', multiplier == -1))
			return (false);
		*nbr = *nbr * 10 + nbr_str[i] - '0';
		i++;
	}
	i += ft_strspn(&nbr_str[i], WHITESPACE);
	*nbr *= multiplier;
	return ((i >= n || !nbr_str[i]) && has_digits);
}
