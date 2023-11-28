/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 21:02:51 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 18:38:41 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	num_src;
	size_t	num_dst;
	size_t	srclen;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size == 0 || size <= dstlen)
	{
		return (size + srclen);
	}
	num_src = 0;
	num_dst = dstlen;
	while ((num_src < (size - dstlen - 1) && (src[num_src] != '\0')))
	{
		dst[num_dst + num_src] = src[num_src];
		num_src++;
	}
	dst[num_dst + num_src] = '\0';
	return (dstlen + srclen);
}
//size is basically the leftover of num_dest if
//you tried to return it @if(size == 0 || size <= num_dest)
// return (size + srclen) cause "man strlcat" says:
// return the total length of the string they tried to create,
// "initial length of dst plus the length of src".
// &
// if strlcat() traverses size characters without finding a NUL, 
// the length of the string is considered to be size.
//
// while ((num_src < (size - dstlen - 1) && (src[num_src] != '\0')))
// This part of the code checks if there is enough space left in 
// the destination buffer to copy characters from the source string.
// The remainder size is used to copy src into dst.
// "man strlcat"-> size - strlen(dst) - 1 bytes
//
// strlcat() functions return the total length of the string they tried
//to create ( basically size + source/destination)
//
//https://www.delorie.com/djgpp/doc/libc/libc_762.html 
//<- read this @ return value
//-The strlcat() function returns the total length of the string that
//would have been created if there was unlimited space.
//
/*
int	main(void)
{
	size_t		sizing = 30;
	char		d[25] = "Length of destination";
	const char	s[25] = "Length of source";

	printf("The total length is: %lu\n", ft_strlcat(d, s, sizing));
	printf("The total length is: %lu\n", strlcat(d, s, sizing));
	return (0);
}
*/
