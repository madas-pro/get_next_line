/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:46:38 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/12 13:36:30 by adolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*str;
	char		*tmp;
	int			newline_pos;

	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (42)
	{
		read(fd, buf, BUFFER_SIZE);
		if (!stash)
			stash = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(stash, buf);
			free(stash);
			stash = ft_strdup(tmp);
			free(tmp);
		}
		newline_pos = ft_search_newline(stash);
		if (newline_pos >= 0)
			break ;
	}
	str = ft_substr(stash, 0, newline_pos);
	stash += newline_pos;
	return (str);
}

#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("pitie.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
