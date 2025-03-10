/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:40:09 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/10 23:16:32 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stdbool.h>
# include <stdlib.h>

bool				ft_strtoi(const char *nbr_str, int *nbr);
bool				ft_strntoi(const char *nbr_str, int *nbr, size_t n);
bool				ft_strtol(const char *nbr_str, long *nbr);
char				*ft_itostr(int nbr);

unsigned long long	ft_abs(long long n);
long long			ft_max(long long n1, long long n2);
long long			ft_min(long long n1, long long n2);
unsigned long long	ft_umax(unsigned long long n1, unsigned long long n2);
unsigned long long	ft_umin(unsigned long long n1, unsigned long long n2);

void				*ft_calloc(size_t n, size_t size);

size_t				ft_nbrlen(unsigned long long nbr, unsigned int base);

#endif
