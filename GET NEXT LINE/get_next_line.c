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

static int  get_line(char **line, char **s, ssize_t read_bytes)
{
    char *temp;
    char *temp2;

    if (read_bytes < 0)
    {
        if (*s != NULL)
        {
            free (*s);
            *s = NULL;
        }
        return (-1);
    }
    if (!read_bytes && !*s)
    {
        *line = ft_strdup("");
        return (0);
    }
    if ((temp = ft_strchr(*s, '\n')))
    {
        *temp = '\0';
        *line = ft_strdup(*s);
        temp2 = ft_strdup(temp + 1);
        free(*s);
        *s = temp2;
        return (1);
    }
    if ((ft_strchr(*s, '\0')))
    {
        *line = ft_strdup (*s);
        free (*s);
        *s = NULL;
    }
    return (0);
}

int get_next_line (int fd, char **line)
{
    static char *s[4096];
    char        *buf;
    ssize_t     read_bytes;

    read_bytes = 0;
    if (fd < 0 || line == NULL || BUFFER_SIZE <= 0 ||
		(!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
        return (-1);
    while ((read_bytes = read(fd, buf, BUFFER_SIZE)) > 0)
    {
        buf[read_bytes] = '\0';
        if (!s[fd])
            s[fd] = ft_strdup(buf);
        else 
            s[fd] = ft_strjoin(s[fd], buf);
        if (ft_strchr(buf, '\n'))
            break ;
    }
    free (buf);
    buf= NULL;
    return (get_line (line, &s[fd], read_bytes)); 
}
/*
int main (void)
{
	int		fd;
	char	*line;
	ssize_t		ret;

	fd = open("test.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		printf("%s\n", line);
	}
	//printf("%s\n", line);
    close(fd);
}

*/
/*
int main (void)
{
    char *line;
    int fd;
    //int fd2;
    fd = open("test.txt", O_RDONLY);


    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);
    }
    close(fd);
    
    fd2 = open("test.txt", O_RDONLY);

    while (get_next_line(fd2, &line))
    {
        printf("%d\n", get_next_line(fd2, &line));
    }
    close(fd2);

    return (0);
}
*/
/*
int	main()
{
	int		fd;
	char	*line;
	fd = open("test.txt", O_RDONLY);
	while (((get_next_line(fd, &line)) > 0))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
}
*/
