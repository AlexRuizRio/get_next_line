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
#define BUFFER_SIZE 5

static	size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

static	char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1)+ ft_strlen(s2);
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len] != '\0')
	{
		str[i] = s2[len];
		i++;
		len++;
	}
	str[i] = '\0';
	return (str);
}

static	char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*cleanline (char *str)
{

}

char	*look_line	(char *str)
{

}

char	*reading_file (int fd, char *str)
{
	char	*buffer;
	size_t 	bytes_read;
	int		i;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(buffer == NULL)
		return (NULL);
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
	if (ft_strlen(str) == 0)
		str = reading_file(fd, str);
	else
		line = look_line(str);
	if (str == NULL)
		retrun (NULL);
	return (line);
}

int main (void)
{
	char	*line;
	int fd = open("test1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf ("Error al abrir el archivo");
		retutn (-1);
	}
	while ((line = get_next_line(fd)) )


	return (0);
}
