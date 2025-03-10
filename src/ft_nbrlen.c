/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:41:47 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/08 06:01:52 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stdlib.h"

size_t	ft_nbrlen(unsigned long long nbr, unsigned int base)
{
	unsigned long long	quotient;

	quotient = nbr / base;
	if (quotient)
		return (ft_nbrlen(quotient, base) + 1);
	else
		return (1);
}
