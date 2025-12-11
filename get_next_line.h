/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adolivie <adolivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:46:58 by adolivie          #+#    #+#             */
/*   Updated: 2025/12/11 02:16:47 by adolivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fnctl.c>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE

/* helpers */
size_t	ft_strlen(const char *str);
char	*ft_strjoin(const char *src1, const char *src2);
char	*ft_strdup_l(const char *string, int len);
int		ft_search_newline(const char *string);

/* get_next_line */
char	*get_next_line(int fd);