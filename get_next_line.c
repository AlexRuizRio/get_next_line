

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
		
	}

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