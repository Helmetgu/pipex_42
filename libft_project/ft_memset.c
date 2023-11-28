/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:56:21 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 15:56:50 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*si;

	si = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		si[i] = c;
		i++;
	}
	return (s);
}
/*
 "Objective of ft_memset":
 fills the first n bytes of the memory area pointed to 
 by s with the constant byte c.

First, change "*s" into a value unsigned char *si.
 while "while (i < n)" is true, copy value "int c"
 to "every index of s".
 
Return (s); 
*/
