/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <alruiz-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:41:18 by alruiz-d          #+#    #+#             */
/*   Updated: 2024/04/03 17:41:23 by alruiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((str && !ft_strchr(str, '\n')) || !str)
		str = ft_reading_file(fd, str);
	if (!str)
		return (NULL);
	line = ft_look_line(str);
	if (!line)
		return (ft_free(&str));
	str = ft_cleanline(str);
	return (line);
}
