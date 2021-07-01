/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:30:29 by rufernan          #+#    #+#             */
/*   Updated: 2021/07/01 19:39:01 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static	int	bytes_under_zero (char **s, ssize_t read_bytes)
{
	if (read_bytes < 0)
	{
		if (*s != NULL)
		{
			free (*s);
			*s = NULL;
		}
		return (1);
	}
	return (0);
}

static	void	end_of_file(char **s, char **line)
{
	*line = ft_strdup (*s);
	free (*s);
	*s = NULL;
}

static	int	get_line (char **line, char **s, ssize_t read_bytes)
{
	char	*temp;
	char	*temp2;

	if ((bytes_under_zero (s, read_bytes)) == 1)
		return (-1);
	if (!read_bytes && !*s)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ft_strchr(*s, '\n'))
	{
		temp = ft_strchr(*s, '\n');
		*temp = '\0';
		*line = ft_strdup(*s);
		temp2 = ft_strdup(temp + 1);
		free(*s);
		*s = temp2;
		return (1);
	}
	if ((ft_strchr(*s, '\0')))
	{
		end_of_file(s, line);
	}
	return (0);
}

int	get_next_line (int fd, char **line)
{
	static char	*s[4096];
	char		*buf;
	ssize_t		read_bytes;

	read_bytes = 0;
	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	read_bytes = read(fd, buf, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		buf[read_bytes] = '\0';
		if (!s[fd])
			s[fd] = ft_strdup(buf);
		else
			s[fd] = ft_strjoin(s[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
		read_bytes = read(fd, buf, BUFFER_SIZE);
	}
	free (buf);
	buf = NULL;
	return (get_line (line, &s[fd], read_bytes));
}
