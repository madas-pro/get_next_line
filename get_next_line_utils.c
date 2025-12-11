/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:46:43 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/11 03:40:09 by adolivie         ###   ########.fr       */
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

char	*ft_strjoin(char *src1, const char *src2)
{
	int		i;
	int		j;
	char	*dest;

	dest = malloc(ft_strlen(src1) + ft_strlen((char *)src2) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src1[i])
	{
		dest[i] = src1[i];
		i++;
	}
	free(src1);
	j = 0;
	while (src2[j])
	{
		dest[i] = (char)src2[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_search_newline(const char *string)
{
	int	i;

	if (!string)
		return (0);
	i = 0;
	while (string[i] != '\n')
	{
		if (string[i] == '\0')
			return (0);
		i++;
	}
	return (i + 1);
}

char	*ft_strdup_l(const char *string, int len)
{
	char	*ptr;
	int		i;

	ptr = malloc(ft_strlen((char *)string) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (string[i] && i < len)
	{
		ptr[i] = string[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
