/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rufernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:11:04 by rufernan          #+#    #+#             */
/*   Updated: 2021/05/17 17:34:55 by rufernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_bzero (void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*(ptr++) = '\0';
		n--;
	}
	return (s);
}
/*int	main(void)
{
	char memory[]= "hoalyryrsdfr";

	printf("%p\n", ft_bzero(memory,   3));
	printf("%s\n", memory);
	printf("%p\n", ft_bzero(memory, 3));

}
*/