/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:57:39 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/22 18:58:37 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stdlib.h"
#include "ft_string.h"

static void	ft_putnbr_to_buffer(char *buffer, char *sign, unsigned int nbr)
{
	unsigned int	sign_len;
	unsigned int	nbr_len;

	ft_strcpy(buffer, sign);
	sign_len = ft_strlen(sign);
	nbr_len = ft_nbrlen_base(nbr, 10);
	buffer[sign_len + nbr_len] = '\0';
	while (nbr_len > 0)
	{
		nbr_len--;
		buffer[sign_len + nbr_len] = nbr % 10 + '0';
		nbr /= 10;
	}
}

char	*ft_itostr(int nbr)
{
	char			*sign;
	unsigned int	unsigned_nbr;
	char			*nbr_str;

	if (nbr < 0)
	{
		sign = "-";
		unsigned_nbr = -nbr;
	}
	else
	{
		sign = "";
		unsigned_nbr = nbr;
	}
	nbr_str = malloc(sizeof(char)
			* (ft_strlen(sign) + ft_nbrlen_base(unsigned_nbr, 10) + 1));
	if (!nbr_str)
		return (NULL);
	ft_putnbr_to_buffer(nbr_str, sign, unsigned_nbr);
	return (nbr_str);
}
