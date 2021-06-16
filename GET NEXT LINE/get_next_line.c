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

int    fill_line (char **s, char **line)
{
    int     len;
    char    *temp;

    len = 0;

    while (*s[len] != '\n' && *s[len])
        len++;
    if (*s[len] == '\n')
    {
        *line = ft_substr (*s, 0, len);
        *temp = ft_strdup (*s + len + 1);
        free(*s);
        *s = temp;
        if (s[0] == '\0')
            free (*s);
            s = NULL;
    }
    else if (*s[len] == '\0')
    {
        *line = ft_strdup(*s);
        free(*s);
        s = NULL;
    }
    return (1);
}

int get_next_line (int fd, char **line)
{
    static char *s;
    char        buf[BUFFER_SIZE + 1];
    char        *tmp;
    int         ret;

    
}
