/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:46:38 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/11 02:19:41 by adolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	int			newline_pos;
	static char	*stash;
	char		*str;
	int			is_newline_read;

	count = 0;
	is_newline_read = 0;
	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (is_newline_read == 0)
	{
		count += read(fd, buf, BUFFER_SIZE);
		stash = ft_strjoin(stash, buf);
		if (newline_pos = ft_search_newline(stash) != 0)
		{
			is_newline_read = 1;
			str = ft_strdup(stash, newline_pos);
			stash += newline_pos;
		}
	}
	return (str);
}

#include <stdio.h>

int	main(void)
{
}
