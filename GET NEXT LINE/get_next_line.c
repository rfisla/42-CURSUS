/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:30:29 by rufernan          #+#    #+#             */
/*   Updated: 2021/06/16 16:30:32 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static int  get_line(char **s, char **line)
{
    int     len;
    char    *temp;

    len = 0;
    
    while ((*s)[len] != '\n' && (*s)[len] != '\0')
        len++;
    if ((*s)[len] == '\n')
    {
        *line = ft_substr(*s, 0, len);
        temp = ft_strdup(&((*s)[len + 1]));
        free(*s);
        *s = temp;
        if ((*s)[0] == '\0')
        {
            free(*s);
            *s = NULL;
        }
    }
    else if((*s)[len] == '\0')
    {
        *line = ft_strdup(*s);
        free(*s);
        *s = NULL;
    }
    return (1);
}

static int  output (char **s, char **line, int read_bytes, int fd)
{
   if (read_bytes < 0)
        return (-1);
    else if (read_bytes == 0 && s[fd] == NULL)
        return (0);
    else 
        return (get_line(&s[fd], line));
}

int get_next_line (int fd, char **line)
{
    static char *s[4096];
    char        *temp;
    char        buf[BUFFER_SIZE];
    int         read_bytes;

    if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
        return (-1);
    while ((read_bytes = read(fd, buf, BUFFER_SIZE)))
    {
        buf[read_bytes] = '\0';
        if (!s[fd])
            s[fd] = ft_strdup(buf);
        else 
        {
            temp = ft_strjoin(s[fd], buf);
            free(s[fd]);
            s[fd] = temp;
        }
        if (ft_strchr(s[fd], '\n'))
            break ;
    }  
    return (output (s, line, read_bytes, fd)); 
 
}


int main (void)
{
    char *line;
    int fd;
    fd = open("test.txt", O_RDONLY);


    while (get_next_line(fd, &line))
    {
        printf("%s\n\n", line);
    }
    close(fd);
    fd = open("test.txt", O_RDONLY);

    while (get_next_line(fd, &line))
    {
        printf("%d\n", get_next_line(fd, &line));
    }

    return (0);
}
