/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:46:38 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/11 03:38:53 by adolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	int			newline_pos;
	static char	*stash;
	char		*str;

	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (42)
	{
		read(fd, buf, BUFFER_SIZE);
		stash = ft_strjoin(stash, buf);
		newline_pos = ft_search_newline(stash);
		if (newline_pos != 0)
		{
			str = ft_strdup_l(stash, newline_pos);
			stash += newline_pos;
			break ;
		}
	}
	return (str);
}
