/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:46:58 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/12 12:24:03 by adolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

/* helpers */
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *src1, const char *src2);
char	*ft_strdup(const char *string);
int		ft_search_newline(const char *string);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* get_next_line */
char	*get_next_line(int fd);