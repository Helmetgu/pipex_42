/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:29:54 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 18:58:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && (i < (size - 1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
 "Objective of strlcpy":
 copy and concatenate strings respectively.
 strlcpy() function copies up to size - 1 characters 
 from the NUL-terminated string src to dst, 
 NULL-terminating the result.

 "Return value":
 return the total length of the string they tried 
 to create.
 "that means the length of src."

 "if size == 0" or lesser than '0' just return the 
 strlen of current src. 
 if not, then enter into while loop, which
 "while (src[i] != '\0' && (i < (size - 1)))"
 which we are trying to copy src into dest with
 the remaining size left. It ends if it is all 
 copied which means we reached the end '\0', or
 we ran out of size space.

 we '\0' the last index of dst and then
 return the total length of src that we did
 up to that point when we tried to copy src into
 dest.
 */
//
/*
int	main(void)
{
	char	source[10] = "marcus";
	char	dest[50] = "hello world byebye";

       	printf("%zu\n", ft_strlcpy(dest, "lorem ipsum dolor sit amet", 0));
	write(1, "\n", 1);
	write(1, dest, 15);

	printf("Source: %s\n", source);
	printf("Destination: %lu\n", ft_strlcpy(dest, source, 10));
	printf("Destination: %lu\n", strlcpy(dest, source, 10));
}
*/
//	cc -lbsd ft_strlcpy.c && ./a.out && rm a.out
