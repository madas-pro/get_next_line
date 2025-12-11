/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:46:43 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/11 00:51:03 by adolivie         ###   ########.fr       */
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

char	*ft_strdup(const char *string)
{
	char	*ptr;
	int		i;

	ptr = malloc(ft_strlen((char *)string) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (string[i])
	{
		ptr[i] = string[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	ft_putstr_l(char *s, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		write(1, s + i, 1);
		i++;
	}
}

int	ft_search_newline(const char *string)
{
	int	i;

	if (!string)
		return (-1);
	i = 0;
	while (string[i] != '\n')
	{
		if (str[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}
