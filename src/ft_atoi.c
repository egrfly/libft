/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 00:53:17 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/03 00:18:02 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"
#include "ft_defs.h"
#include "ft_string.h"

int	ft_atoi(const char *nstr)
{
	int		n;
	int		multiplier;

	n = 0;
	multiplier = 1;
	nstr += ft_strspn(nstr, WHITESPACE);
	if (*nstr == '+' || *nstr == '-')
	{
		if (*nstr == '-')
			multiplier = -1;
		nstr++;
	}
	while (ft_isdigit(*nstr))
	{
		n = n * 10 + *nstr - '0';
		nstr++;
	}
	return (n * multiplier);
}
