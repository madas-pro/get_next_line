/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:39:32 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/17 14:39:46 by adolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(const char *src1, const char *src2)
{
	int		i;
	int		j;
	char	*dest;

	dest = malloc(ft_strlen(src1) + ft_strlen(src2) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src1[i])
	{
		dest[i] = src1[i];
		i++;
	}
	j = 0;
	while (src2[j])
	{
		dest[i] = src2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s <= start)
		return (ft_strdup(""));
	if (len_s - start < len)
		len = len_s - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr = ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *string)
{
	char	*ptr;
	int		string_len;

	string_len = ft_strlen(string);
	ptr = malloc(string_len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, string, string_len);
	ptr[string_len] = '\0';
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	unsigned char	p;

	i = 0;
	p = (unsigned char)c;
	while (str[i] != '\0' && str[i] != p)
		i++;
	if (str[i] == '\0' && p != '\0')
		return (NULL);
	return ((char *)&str[i]);
}
