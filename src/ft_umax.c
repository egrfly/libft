/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:41:28 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:01:22 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_umax(unsigned long long n1, unsigned long long n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}
