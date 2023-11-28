/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:56:19 by mlow              #+#    #+#             */
/*   Updated: 2023/09/22 15:48:56 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*si;

	i = 0;
	si = (unsigned char *)s;
	while (i < n)
	{
		si[i] = '\0';
		i++;
	}
}
/*
 "Objective of bzero":
 To erase the data in the n bytes of the memory starting
 at the location pointed to by s, by writing 0 to that area.
 There is no return value.

"size_t i" is to compare "size_t n" & "unsigned char *si"
 is used to convert value of "void *s" into 
 "Unsigned char" value of *si.

 while (i < n)
        {
                si[i] = '\0';
                i++;
        }
This part of the code just turns all into "'\0'".
*/
//
