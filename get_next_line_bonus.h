/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:15:00 by rmanuel           #+#    #+#             */
/*   Updated: 2021/03/11 12:18:29 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int		get_next_line(int fd, char **line);
int		ft_strlcpy(char *dst, const char *src, int dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strjoin_free(char *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	*make_line(char *save, char **line);
int		find_nl(char *str);

#endif
