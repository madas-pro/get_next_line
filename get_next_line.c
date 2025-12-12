/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:46:38 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/12 12:26:56 by adolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	int			newline_pos;
	static char	*stash;
	char		*str;
	char		*tmp;

	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 100);
	if (!buf)
		return (NULL);
	while (42)
	{
		read(fd, buf, BUFFER_SIZE);
		if (!stash)
			stash = ft_strdup_l(buf);
		else
			tmp = ft_strjoin(stash, buf);
		free(stash) stash = ft_strdup_l(tmp);
		if (ft_search_newline(stash) >= 0)
			break ;
	}
	// 	if (newline_pos >= 0)
	// 	{
	// 		str = ft_strdup_l(stash, newline_pos);
	// 		stash += newline_pos;
	// 		break ;
	// 	}
	// }
	// return (str);
}

#include <stdio.h>

int	main(void)
{
	/*int fd = open("pitie.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));*/
}