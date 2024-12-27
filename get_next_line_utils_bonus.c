#include "get_next_line_bonus.h"

size_t  ft_strlen(const char *s)
{
        int     i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *d;
        char    *s;

        if (!s1)
                s1 = "";
        if (!s2)
                s2 = "";
        d = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
        if (!d)
                return (NULL);
        s = d;
        while (*s1)
                *d++ = *s1++;
        while (*s2)
                *d++ = *s2++;
        *d = '\0';
        return (s);
}

char    *ft_strchr(const char *string, int searchedChar )
{
        char    *str;

        str = (char *)string;
        while (*str != searchedChar && *str != 0)
                str++;
        if (*str == searchedChar)
                return (str);
        else
                return (NULL);
}

char    *ft_strdup(const char *s)
{
        char    *d;
        size_t  i;

        i = ft_strlen(s);
        d = malloc(i + 1);
        if (d == NULL)
                return (NULL);
        ft_memcpy(d, s, i);
        d[i] = '\0';
        return (d);
}

size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
        size_t  i;
        int             s;

        i = 0;
        s = ft_strlen(src);
        if (size != 0)
        {
                while (src[i] && i < size - 1)
                {
                        dst[i] = src[i];
                        i++;
                }
                dst[i] = '\0';
        }
        return (s);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
        unsigned char           *d;
        const unsigned char     *s;

        d = (unsigned char *)dest;
        s = (const unsigned char *)src;
        if (!dest || !src)
                return (NULL);
        while (n--)
                *d++ = *s++;
        return (dest);
}
