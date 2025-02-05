/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstarts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 01:52:26 by emflynn           #+#    #+#             */
/*   Updated: 2025/02/05 01:54:05 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_string.h"

bool    ft_strstarts(const char *str, const char *prefix)
{
    return (ft_strncmp(str, prefix, ft_strlen(prefix)) == 0);
}
