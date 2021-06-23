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

void	ft_strclr(char *s)
{
	if (s)
	{
		while (*s)
		{
			*s = '\0';
			s++;
		}
	}
}

char    *check_s(char *s, char **line)
{
    char    *p_n;

    p_n = NULL;
    if (s)
    {
        if ((p_n = ft_strchr(s, '\n')))
        {
            *p_n = '\0';
            *line = strdup(s);
            strcpy(s, ++p_n);
        }
        else
        {
            *line = strdup(s);
            ft_strclr(s);
        }
    }
    else
        *line = ft_strnew(1);
    return (p_n);
}
int get_next_line (int fd, char **line)
{
    static char *s;
    char        buf[BUFFER_SIZE + 1];
    char        *p_n;
    int         read_bytes;
    char        *tmp; //? sin usar esta variable mismo resultado

    if (fd < 0 || BUFFER_SIZE <= 0 || !line)
        return (-1);
    p_n = check_s(s, line);
    while (!p_n && (read_bytes = read(fd, buf, BUFFER_SIZE))> 0)
    {
        if (read_bytes == -1)
            return (-1);
        buf[read_bytes] = '\0';
        if ((p_n = ft_strchr(buf, '\n')))
        {
            *p_n = '\0';
            p_n++;
            s = ft_strdup(p_n);
        }
        tmp = *line;
        *line = ft_strjoin(*line, buf);
        free(tmp);
    }
    if (read_bytes == 0)
        {
            *line = ft_strjoin(*line, buf);
            return (0);

        }

    return (1);
}


int main (void)
{
    char *line;
    int fd;
    fd = open("test.txt", O_RDONLY);


    while (get_next_line(fd, &line))
        printf("%s\n", line);
    
    return (0);

}
