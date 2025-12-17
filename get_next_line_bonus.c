/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:41:27 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/17 15:36:29 by adolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*join_line(char *buffer, char *rest)
{
	char	*str;

	if (!rest)
		return (ft_strdup(buffer));
	str = ft_strjoin(rest, buffer);
	if (!str)
	{
		free(rest);
		return (NULL);
	}
	free(rest);
	return (str);
}

char	*handle_rest(char **rest)
{
	char	*newline;
	char	*line;
	char	*tmp;
	int		len;

	if (!*rest || !**rest)
		return (free(*rest), *rest = NULL, NULL);
	newline = ft_strchr(*rest, '\n');
	if (!newline)
	{
		line = ft_strdup(*rest);
		return (free(*rest), *rest = NULL, line);
	}
	len = (int)((newline - *rest) + 1);
	line = ft_substr(*rest, 0, len);
	if (!line)
		return (free(*rest), *rest = NULL, NULL);
	tmp = ft_strdup(newline + 1);
	if (!tmp)
		return (free(*rest), *rest = NULL, free(line), NULL);
	return (free(*rest), *rest = tmp, line);
}

char	*get_next_line(int fd)
{
	static char	*rest[4096];
	char		*buffer;
	char		*newline;
	int			nb_read;

	newline = NULL;
	if (rest[fd])
		newline = ft_strchr(rest[fd], '\n');
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(rest[fd]), rest[fd] = NULL, NULL);
	while (!newline)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read < 0)
			return (free(buffer), free(rest[fd]), rest[fd] = NULL, NULL);
		if (nb_read == 0)
			break ;
		buffer[nb_read] = '\0';
		rest[fd] = join_line(buffer, rest[fd]);
		if (!rest[fd])
			return (free(buffer), NULL);
		newline = ft_strchr(rest[fd], '\n');
	}
	return (free(buffer), handle_rest(&rest[fd]));
}
