/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 09:46:11 by rmanuel           #+#    #+#             */
/*   Updated: 2021/03/10 19:20:19 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int			find_nl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char		*make_line(char *save, char **line)
{
	int		i_nl;
	char	*tmp_save;

	i_nl = find_nl(save);
	if (i_nl == -1)
	{
		*line = ft_strdup(save);
		free(save);
		return (NULL);
	}
	*line = (char *)ft_calloc(i_nl + 1, sizeof(char));
	tmp_save = ft_strdup(&save[i_nl + 1]);
	ft_strlcpy(*line, save, i_nl + 1);
	free(save);
	save = NULL;
	return (tmp_save);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	static char	*save;
	char		*buffer;

	if (read(fd, 0, 0) == -1 || fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (-1);
	while (find_nl(save) == -1 && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (save)
			save = ft_strjoin_free(save, buffer);
		else
			save = ft_strdup(buffer);
	}
	if (ret < 0)
		return (-1);
	save = make_line(save, line);
	free(buffer);
	buffer = NULL;
	if (save)
		return (1);
	return (0);
}
