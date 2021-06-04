/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 17:14:11 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/24 17:24:36 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* Allocates memory for an array of nmemb elements of size bytes each and 
 *returns a pointer to the allocated memory. The memory is set to zero. If nmemb
 *or size is 0, then calloc() returns either NULL,or a unique pointer value that 
 *can later be successfully passed to free(). */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, size * count);
	return (ptr);
}
