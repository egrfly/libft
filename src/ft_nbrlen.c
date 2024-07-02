/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:41:47 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 18:04:45 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stdlib.h"

size_t	ft_nbrlen(unsigned long long n, unsigned int base)
{
	unsigned long long	quotient;

	quotient = n / base;
	if (quotient)
		return (ft_nbrlen(quotient, base) + 1);
	else
		return (1);
}
