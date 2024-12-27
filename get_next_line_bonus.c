#include "get_next_line_bonus.h"

char    *join_old_new(char *old, char *new)
{
        char    *joind;
        joind = ft_strjoin(old, new);
        free(old);
        return (joind);
}

char    *filter_line(char **buffer)
{
        char    *line;
        char    *after_newline;
        char    *temp;
        size_t  len;

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

char    *read_line(int fd, char **buffer)
{
        char    *temp;
        ssize_t bytes_read;

        temp = malloc(BUFFER_SIZE + 1);
        if (!temp)
                return (NULL);
        while (!buffer[fd] || !ft_strchr(buffer[fd], '\n'))
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
                buffer[fd] = join_old_new(buffer[fd], temp);
        }
        free(temp);
        return (buffer[fd]);
}

char    *get_next_line(int fd)
{
        static char     *buffer[1024];

        if (fd < 0 || BUFFER_SIZE <= 0)
                return (NULL);
        buffer[fd] = read_line(fd, buffer);
        if (!buffer[fd] || buffer[fd][0] == '\0')
        {
                free(buffer[fd]);
                return (NULL);
        }
        return (filter_line(&buffer[fd]));
}


int main()
{
    int fd = open("text.txt", O_RDWR | O_CREAT, 0644);
    int fd1 = open("text1.txt", O_RDWR | O_CREAT, 0644);
    int fd2 = open("text2.txt", O_RDWR | O_CREAT, 0644);

    if (fd < 0 || fd1 < 0 || fd2 < 0)
    {
        perror("Error opening file");
        return 1;
    }
    char *line1;
    char *line2;
    char *line3;

    while (line1 && line2 && line3)
    {
    	  printf("f1 %s\n", line1 = get_next_line(fd));
 	  printf("f2 %s\n", line2 = get_next_line(fd1));
	  printf("f3 %s\n", line3 = get_next_line(fd2));
          free(line1);
	  free(line2);
	  free(line3);
    }
    close(fd);
    close(fd1);
    close(fd2);
}
