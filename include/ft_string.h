/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:40:09 by emflynn           #+#    #+#             */
/*   Updated: 2025/03/08 06:15:24 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stdbool.h>
# include <stdlib.h>

bool	ft_strall(const char *str, bool (*f)(char));
bool	ft_strnall(const char *str, bool (*f)(char), size_t n);
bool	ft_strany(const char *str, bool (*f)(char));
bool	ft_strnany(const char *str, bool (*f)(char), size_t n);

void	ft_bzero(void *ptr, size_t n);
void	*ft_memccpy(void *dest, const void *src, char c, size_t n);
void	*ft_memchr(const void *ptr, char c, size_t n);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memrchr(const void *ptr, char c, size_t n);
void	*ft_memset(void *ptr, char c, size_t n);

char	**ft_split(const char *str, const char *set);
void	ft_split_destroy(char ***splits);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strchr(const char *str, char c);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strcpy(char *dest, const char *src);
size_t	ft_strcspn(const char *str, const char *reject);
char	*ft_strdup(const char *str);
bool	ft_strends(const char *str, const char *suffix);
void	ft_striteri(char *str, void (*f)(unsigned int, char *));
char	*ft_strjoin(const char *str1, const char *str2);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char	*ft_strncat(char *dest, const char *src, size_t n);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strndup(const char *str, size_t n);
size_t	ft_strnlen(const char *str, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strrange(const char *str, unsigned int start, unsigned int end);
char	*ft_strrchr(const char *str, char c);
size_t	ft_strspn(const char *str, const char *accept);
bool	ft_strstarts(const char *str, const char *prefix);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strtrim(const char *str, const char *set);
char	*ft_substr(const char *str, unsigned int start, size_t n);

#endif
