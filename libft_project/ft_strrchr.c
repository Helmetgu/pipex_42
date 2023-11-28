/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:42:52 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 20:57:39 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		num_source;
	char	character;

	character = (char)c;
	num_source = ft_strlen(s);
	if (character == '\0')
		return ((char *)s + ft_strlen(s));
	while (num_source >= 0)
	{
		if (s[num_source] == character)
			return ((char *)s + num_source);
		num_source--;
	}
	return (NULL);
}
/*
 "Objective of strrchr":
 function returns a pointer to the last 
 occurrence of the character c in the string s.

"Return Values":
 If little is an empty string, big is returned; if 
 little occurs nowhere in big, NULL is returned; 
 otherwise a pointer to the first character of the 
 first occurrence of little is returned.

 Works like strchr but backwards.

if c is an empty int,
 "-if (character == '\0')
                return ((char *)s + ft_strlen(s));"
The terminating null byte is considered part of the string,
 so that if c is specified as '\0', these 
 functions return a pointer to the terminator.
What it means is that if const char = "I luv choco'\0'"
 read until the '\0' part.

if c occurs nowhere in big,
 "return (NULL)"

we look through and return the moment we start to hit 
the value of "character(c)", just like strchr but
backwards.
*/
//
/*
int	main(void)
{
	printf("%s",ft_strrchr("hel @lo @blocks @nickel @shotgun",'@'));
	return (0);
}
*/
