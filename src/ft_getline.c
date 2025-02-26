/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emflynn <emflynn@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:52:28 by emflynn           #+#    #+#             */
/*   Updated: 2025/02/26 15:47:08 by emflynn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_defs.h"
#include "ft_string.h"

static void	ft_free_on_completion_or_error(char **line, ssize_t read_char_count)
{
	if (read_char_count < 0 || (read_char_count == 0 && ft_strlen(*line) == 0))
	{
		free(*line);
		*line = NULL;
	}
}

static char	*ft_extract_line_from_buffer(char *buffer)
{
	char	*line;
	char	*newline;

	newline = ft_strchr(buffer, '\n');
	line = ft_strndup(buffer, newline - buffer);
	ft_strncpy(buffer, newline + 1, buffer + ft_strlen(buffer) - newline);
	return (line);
}

static void	ft_extend_line_from_buffer(char **line, char *buffer, size_t n)
{
	size_t	original_char_count;
	char	*extended_line;

	original_char_count = ft_strlen(*line);
	extended_line = malloc(sizeof(char) * (original_char_count + n + 1));
	if (extended_line)
	{
		ft_memmove(extended_line, *line, original_char_count);
		ft_memmove(extended_line + original_char_count, buffer, n);
		extended_line[original_char_count + n] = '\0';
	}
	free(*line);
	*line = extended_line;
}

static void	ft_extend_line_from_fd(int fd, char **line, char *buffer)
{
	int		read_char_count;
	char	*newline;

	while (*line)
	{
		read_char_count = read(fd, buffer, BUFFER_SIZE);
		if (read_char_count >= 0)
			buffer[read_char_count] = '\0';
		ft_free_on_completion_or_error(line, read_char_count);
		if (read_char_count <= 0)
			break ;
		newline = ft_strchr(buffer, '\n');
		if (newline)
		{
			ft_extend_line_from_buffer(line, buffer, newline - buffer);
			ft_memmove(buffer, newline + 1, buffer + read_char_count - newline);
			break ;
		}
		else
			ft_extend_line_from_buffer(line, buffer, read_char_count);
	}
}

char	*ft_getline(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*newline;
	char		*line;

	if (fd < 0)
		return (NULL);
	newline = ft_strchr(buffer, '\n');
	if (newline)
		line = ft_extract_line_from_buffer(buffer);
	else
	{
		line = ft_strdup(buffer);
		ft_extend_line_from_fd(fd, &line, buffer);
	}
	if (!line)
		buffer[0] = '\0';
	return (line);
}
