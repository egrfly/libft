/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:40:09 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 17:03:25 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdbool.h>
# include <stdlib.h>

int					ft_atoi(const char *nstr);
bool				ft_atoi_strict(const char *nstr, int *n);
char				*ft_itoa(int n);

unsigned long long	ft_abs(long long n);
long long			ft_max(long long n1, long long n2);
long long			ft_min(long long n1, long long n2);
unsigned long long	ft_umax(unsigned long long n1, unsigned long long n2);
unsigned long long	ft_umin(unsigned long long n1, unsigned long long n2);

void				*ft_calloc(size_t n, size_t size);

size_t				ft_nbrlen(unsigned long long n, unsigned int base);

#endif
