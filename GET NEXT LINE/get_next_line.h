/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 18:00:01 by rufernan          #+#    #+#             */
/*   Updated: 2021/07/01 16:58:56 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int				get_next_line(int fd, char **line);
char			*ft_strchr (const char *str, int c);
size_t			ft_strlen (const char *s);
char			*ft_strjoin (char const *s1, char const *s2);
char			*ft_strdup (const char *s1);

#endif
