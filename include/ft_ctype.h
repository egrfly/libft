/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:40:09 by emflynn           #+#    #+#             */
/*   Updated: 2024/07/02 10:03:29 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

# include <stdbool.h>

bool	ft_isalnum(char c);
bool	ft_isalpha(char c);
bool	ft_isascii(char c);
bool	ft_isblank(char c);
bool	ft_iscntrl(char c);
bool	ft_isdigit(char c);
bool	ft_isgraph(char c);
bool	ft_islower(char c);
bool	ft_isprint(char c);
bool	ft_ispunct(char c);
bool	ft_isspace(char c);
bool	ft_isupper(char c);
bool	ft_isxdigit(char c);
char	ft_tolower(char c);
char	ft_toupper(char c);

#endif
