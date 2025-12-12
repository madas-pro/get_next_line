/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:46:43 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/12 12:26:50 by adolivie         ###   ########.fr       */
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

	dest = malloc(ft_strlen(src1) + ft_strlen((char *)src2) + 101);
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
		return (-1);
	i = 0;
	while (string[i])
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdup(const char *string)
{
	char	*ptr;
	int		i;

	ptr = malloc(ft_strlen((char *)string) + 101);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*ptr;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (!s)
		return (NULL);
	if (len > slen - start)
		len = slen - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
