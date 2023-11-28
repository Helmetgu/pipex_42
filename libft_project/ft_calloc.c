/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:40:37 by mlow              #+#    #+#             */
/*   Updated: 2023/09/22 16:25:13 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	result = (void *)malloc(nmemb * size);
	if (result != NULL)
		ft_bzero(result, nmemb * size);
	else
	{
		return (NULL);
	}
	return (result);
}
/*
 "Objective of calloc":
 allocates memory for an array of nmemb elements 
 of size bytes and returns a pointer to the
 allocated memory.
 Memory is set to zero.
 If either nmemb or size is = 0, calloc returns
 "NULL" or a unique pointer value passed to free().

"result" is a void value as we want to return void,
 it is also a pointer as that is what the function
 wants.

"Remember, think about cookies and their cookie size"
 nmemb - cookie, size - cookie size.

"Allocates memory for an array of nmemb elements".
Using "malloc", we firstly "(void *)" malloc as that
 is the value it uses, we don't use "sizeof(void)" as
 it will not compile on a C compiler, an imcomplete
 object with emptys set of values. Do a if should it
 fails the allocation.

If it does not fail, place and use function bzero to
 erase data (nmemb * size). (Don't need to = to
 something. Just stand alone).
 "You eat the cookies piece by piece"
 "You do this by breaking all cookies into pieces"
 "so after cookies x size, you ate all the cookies."

Return value after using bzero function working.
	"return (result);"

int	main(void)
{
	printf("Size of void: %lu\n", sizeof(void));
	return (0);
}
*/
