/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:40:22 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/04/12 16:40:26 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_cleanline(char *str)
{
	char	*strnew;
	char	*temchr;
	int		len;

	temchr = ft_strchr(str, '\n');
	if (!temchr)
	{
		strnew = NULL;
		return (ft_free(&str));
	}
	else
		len = (temchr - str) + 1;
	if (!str[len])
		return (ft_free(&str));
	strnew = ft_substr(str, len, ft_strlen(str) - len);
	if (!strnew)
		return (NULL);
	ft_free(&str);
	return (strnew);
}

char	*ft_look_line(char *str)
{
	char	*line;
	char	*temchr;
	int		len;

	temchr = ft_strchr(str, '\n');
	len = (temchr - str) + 1;
	line = ft_substr(str, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_reading_file(int fd, char *str)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&str));
	bytes_read = 1;
	buffer[0] = '\0';
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	free(buffer);
	if (bytes_read == -1)
		return (ft_free(&str));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((str[fd] && !ft_strchr(str[fd], '\n')) || !str[fd])
		str[fd] = ft_reading_file(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_look_line(str[fd]);
	if (!line)
		return (ft_free(&str[fd]));
	str[fd] = ft_cleanline(str[fd]);
	return (line);
}
