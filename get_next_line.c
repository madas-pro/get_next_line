/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:46:38 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/11 01:31:20 by adolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	int			newline_pos;
	static int	count;

	count = 0;
	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	while (...)
	{
		count += read(fd, buf, BUFFER_SIZE);
		stash = ft_strdup(buf);
		newline_pos = ft_search_newline(stash);
		ft_putstr(stash, newline_pos);
	}
}

#include <stdio.h>

int	main(void)
{
}
