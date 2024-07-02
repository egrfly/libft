/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 20:14:25 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 16:55:53 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_defs.h"
#include "ft_string.h"

bool	ft_isspace(char c)
{
	return (c && ft_strchr(WHITESPACE, c));
}
