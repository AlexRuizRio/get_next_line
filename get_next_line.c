/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alruiz-d <marvin@42.fr>                    +#+  +:+       +#+        */
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

char	*ft_cleanline (char *str)
{
	char	*strnew;
	int		i;
	int		j;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	j = i;
	while(str[i] != '\0')
		i++;
	strnew = (char *)malloc(sizeof(char) * (i - j + 1));
	if (strnew == NULL)
		return (NULL);
	i = 0;
	while (str[j] != '\0')
		strnew[i++] = str[j++];
	free(str);
	return(strnew);
}

char	*ft_look_line	(char *str)
{
	char	*line;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_reading_file (int fd, char *str)
{
	char	*buffer;
	size_t 	bytes_read;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(buffer == NULL)
		return (ft_free(&str));
		//PENDIENTE DE ACTUALIZAR
	bytes_read = 1;
	while (!(ft_strchr(buffer, '\n')) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin (str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <=0)
    	return (NULL);
	if((str && !ft_strchr(str, '\n')) || !str)
		str = reading_file(fd, str);
	if (str == NULL)
		retrun (NULL);	
	line = look_line(str);
	str = cleanline(str);
	return (line);
}
