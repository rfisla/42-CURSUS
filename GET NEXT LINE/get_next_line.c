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

int get_next_line (int fd, char **line)
{
    static char *s;
    char        buf[BUFFER_SIZE + 1];
    char        *p_n;
    int         read_bytes;
    char        *tmp;

    p_n = NULL;
    if (s)
        *line = ft_strdup(s);
    else
        *line = ft_strnew(1);
    while (!p_n && (read_bytes = (fd, buf, BUFFER_SIZE)))
    {
        buf[read_bytes] = '\0';
        if ((p_n = ft_strchr(buf, '\n')))
        {
            *p_n = '\0';
            p_n++;
            s = ft_strdup(p_n);

        }
    }
    tmp = *line;
    *line = ft_strjoin(*line, buf);
    free(tmp);
    return (0);
}


int main (void)
{
    char *line;
    int fd;
    fd = open("test.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("%s\n\n", line);
    
    get_next_line(fd, &line);
    printf("%s\n\n", line);

    while(get_next_line(fd, &line))
        printf("%s\n\n", line);
    
    return (0);

}
