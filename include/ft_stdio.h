/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:40:09 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 21:14:12 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

char	*ft_getline(int fd);

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(const char *str);
void	ft_putendl_fd(const char *str, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(const char *str);
void	ft_putstr_fd(const char *str, int fd);

int		ft_dprintf(int fd, const char *str, ...);
int		ft_printf(const char *str, ...);

#endif
