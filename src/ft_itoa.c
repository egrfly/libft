/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:57:39 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 18:20:17 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stdlib.h"
#include "ft_string.h"

static void	ft_putnbr_to_buffer(char *buffer, char *sign, unsigned int n)
{
	unsigned int	sign_len;
	unsigned int	n_len;

	ft_strcpy(buffer, sign);
	sign_len = ft_strlen(sign);
	n_len = ft_nbrlen(n, 10);
	buffer[sign_len + n_len] = '\0';
	while (n_len > 0)
	{
		n_len--;
		buffer[sign_len + n_len] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char			*sign;
	unsigned int	unsigned_n;
	char			*str_n;

	if (n < 0)
	{
		sign = "-";
		unsigned_n = -n;
	}
	else
	{
		sign = "";
		unsigned_n = n;
	}
	str_n = malloc(sizeof(char)
			* (ft_strlen(sign) + ft_nbrlen(unsigned_n, 10) + 1));
	if (!str_n)
		return (NULL);
	ft_putnbr_to_buffer(str_n, sign, unsigned_n);
	return (str_n);
}
