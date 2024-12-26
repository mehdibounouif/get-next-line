#include "get_next_line.h"

char	*join_old_new(char *old, char *new)
{
	char	*joind;
	joind = ft_strjoin(old, new);
	free(old);
	return (joind);
}

char	*filter_line(char **buffer)
{
	char	*line;
	char	*after_newline;
	char	*temp;
	size_t	len;

	after_newline = ft_strchr(*buffer, '\n');
	if (!after_newline)
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (line);
	}
	len = after_newline - *buffer + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *buffer, len + 1);
	temp = ft_strdup(after_newline + 1);
	free(*buffer);
	*buffer = temp;
	return (line);
}

char	*read_line(int fd, char *buffer)
{
	char	*temp;
	ssize_t	bytes_read;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (!buffer || !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			return (NULL);
		}
		if (bytes_read == 0)
			break;
		temp[bytes_read] = '\0';
		buffer = join_old_new(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer || buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (filter_line(&buffer));
}

int	main()
{
	char	*l;
	int	fd = open("test.txt", O_RDWR | O_CREAT, 0644);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while (l = get_next_line(fd))
	{
		printf("%s -- \n", l);
		free(l);
	}
	close(fd);
}

