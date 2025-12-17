/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 19:15:45 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/17 15:19:28 by adolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*read_file(int fd, char *stash, char *buf)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(stash), NULL);
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buf);
		free(stash);
		if (!tmp)
			return (NULL);
		stash = tmp;
		if (ft_strchr(stash, '\n'))
			break ;
	}
	return (stash);
}

static char	*get_line(char *line)
{
	char	*stash;
	int		i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;

	if (!stash)
		stash = ft_strdup("");
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
	{
		free(stash);
		return (NULL);
	}
	line = read_file(fd, stash, buf);
	free(buf);
	if (!line || line[0] == '\0')
	{
		free(line);
		stash = NULL;
		return (NULL);
	}
	stash = get_line(line);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("pitie.txt", O_RDONLY);
		line = get_next_line(fd);
		printf("%s", line);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	close(fd);
	return (0);
}
*/