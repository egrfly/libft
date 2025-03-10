/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:53:17 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/10 23:14:32 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "ft_ctype.h"
#include "ft_defs.h"
#include "ft_string.h"

static bool	would_surpass_limit(long nbr, int next_digit, bool is_negative)
{
	long	nbr_cutoff;
	int		next_digit_cutoff;

	if (is_negative)
	{
		nbr_cutoff = LONG_MIN / 10;
		next_digit_cutoff = LONG_MIN % 10;
		if (next_digit_cutoff > 0)
		{
			next_digit_cutoff -= 10;
			nbr_cutoff += 1;
		}
		nbr_cutoff = -nbr_cutoff;
		next_digit_cutoff = -next_digit_cutoff;
	}
	else
	{
		nbr_cutoff = LONG_MAX / 10;
		next_digit_cutoff = LONG_MAX % 10;
	}
	return (nbr > nbr_cutoff
		|| (nbr == nbr_cutoff && next_digit > next_digit_cutoff));
}

bool	ft_strtol(const char *nbr_str, long *nbr)
{
	int		multiplier;
	bool	has_digits;
	size_t	i;

	*nbr = 0;
	multiplier = 1;
	has_digits = false;
	i = ft_strspn(nbr_str, WHITESPACE);
	if (nbr_str[i] == '+' || nbr_str[i] == '-')
	{
		if (nbr_str[i] == '-')
			multiplier = -1;
		i++;
	}
	while (ft_isdigit(nbr_str[i]))
	{
		has_digits = true;
		if (would_surpass_limit(*nbr, nbr_str[i] - '0', multiplier == -1))
			return (false);
		*nbr = *nbr * 10 + nbr_str[i] - '0';
		i++;
	}
	i += ft_strspn(&nbr_str[i], WHITESPACE);
	*nbr *= multiplier;
	return (!nbr_str[i] && has_digits);
}
