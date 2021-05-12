/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:14:12 by rmanuel           #+#    #+#             */
/*   Updated: 2021/03/11 12:18:48 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int src_i;
	int src_len;

	if (!dst)
		return (-1);
	src_i = 0;
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	while (src_i < src_len && src_i + 1 < dstsize)
	{
		dst[src_i] = src[src_i];
		src_i++;
	}
	if (dstsize > 0)
		dst[src_i] = '\0';
	return (src_len);
}

char		*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (0);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}

char		*ft_strjoin_free(char *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		k;

	if (!s2)
		return (0);
	i = 0;
	k = 0;
	if (!(s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1 && s1[i])
		s3[k++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
	{
		s3[k] = s2[i];
		i++;
		k++;
	}
	s3[k] = '\0';
	free(s1);
	return (s3);
}

void		*ft_calloc(size_t count, size_t size)
{
	char *ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void		*ft_memset(void *b, int c, size_t len)
{
	char	*newb;

	newb = (char *)b;
	while (len > 0)
	{
		newb[len - 1] = c;
		len--;
	}
	return (b);
}
