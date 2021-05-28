#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *newchain;
    size_t  start;
    size_t  end;
    size_t  len;
    
    if (!s1 || !set)
        return (NULL);
    start = 0;
    while (s1[start] != '\0' && ft_strchr(set, s1[start]))
        start++;
    end = ft_strlen(s1);
    while (end > start && ft_strchr(set, s1[end]))
    {
        end--;
    }
    newchain = (char *)malloc(sizeof(*s1) * (end - start + 1));
    if (!newchain)
        return (NULL);
    len = 0;
    while(start < end)
    {
        newchain[len] = s1[start];
        len++;
        start++;
    }
    newchain[start] = '\0';
    return (newchain);
}
