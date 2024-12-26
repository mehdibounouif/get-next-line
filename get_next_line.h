#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

char    *join_old_new(char *old, char *new);
char    *filter_line(char **buffer);
char    *read_line(int fd, char *buffer);
char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strchr(const char *string, int searchedChar);
char    *ft_strdup(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t size);
void    *ft_memcpy(void *dest, const void *src, size_t n);

#endif
