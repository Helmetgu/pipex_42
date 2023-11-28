/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:25:09 by mlow              #+#    #+#             */
/*   Updated: 2023/09/22 20:48:46 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*si;
	unsigned char			character;

	si = (const unsigned char *)s;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (si[i] == character)
			return ((void *)(si + i)); 
		i++;
	}
	return (NULL);
}
/*
 "Objective of memchr"
 scans the initial n bytes of the memory area 
 pointed to by s for the first instance of c.
 Both c and the bytes of the memory area pointed 
 to by s are interpreted as unsigned char.

Basically, within the string("const void") provided, 
 find the "first "value "int c", within the limits 
 provided by "size_t n".

int	main(void)
{
	char	data[10] = "qrstpax";

	printf("Character taken is: %s\n", (char *)ft_memchr(&data[0], 't', 7));
	printf("Character taken is: %s\n", (char *)ft_memchr("tab", -1, 7));
	printf("Character takentest is: %s\n", (char *)memchr(&data[0], 't', 7));
	return (0);
}
*/
