/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:20:17 by mlow              #+#    #+#             */
/*   Updated: 2023/09/22 21:32:29 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*si;
	unsigned char	*di;

	si = (unsigned char *)src;
	di = (unsigned char *)dest;
	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while (i < n)
	{
		di[i] = si[i];
		i++;
	}
	return (dest);
}
/*
 "Objective of memcpy":
 The  memcpy() function copies n bytes from memory area 
 src to memory area dest.  The memory areas must not 
 overlap. Use memmove(3) if the memory areas do overlap.

The memcpy() function returns a pointer to dest.

By changing the values of const void into unsigned char,
 we can then check the values. Should dest and src 
 are "NULL", return value of that dest(NULL).

If it is not NULL, copy the value from source until 
 the limit size_t n.

The difference between this and memmove is that
 if you tried to copy a value with src and that src
 actually took its value from dest, what happens is that
 eventually when the src tries to change the value that
 it is pointing to: E.g: 1"23"45-> 1"22"22.
memmove however, will not have this issue as it will create
a temporary buffer that has the values of src unaffected
by anything which will then send over to dest.
*/
