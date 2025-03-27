/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:41:47 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/22 18:22:08 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stdlib.h"

size_t	ft_nbrlen_base(unsigned long long nbr, unsigned int base)
{
	unsigned long long	quotient;

	quotient = nbr / base;
	if (quotient)
		return (ft_nbrlen_base(quotient, base) + 1);
	else
		return (1);
}
