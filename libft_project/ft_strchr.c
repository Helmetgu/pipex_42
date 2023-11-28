/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:10:04 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 18:06:55 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		num_source;
	char	character;

	character = (char)c;
	if (character == '\0')
		return ((char *)s + ft_strlen(s));
	num_source = 0;
	while (s[num_source] != '\0')
	{
		if (s[num_source] == character)
			return ((char *)s + num_source);
		num_source++;
	}
	return (NULL);
}
/*
 "Objective of strchr":
 The strchr() function returns a pointer to the first 
 occurrence of the character c in the string s.

 "Return value":
 We are to return a pointer to the matched character of
 the string("(s[num_source] == character)") or "NULL"
 should character not be found.

 Let the terminating null byte alone, it is counted as
 part of the string so if c is specified as '\0', 
 these functions return a pointer to the terminator.

 "if (character == '\0')
                return ((char *)s + ft_strlen(s));"
This part of the code is important, should "int c"
 empty and not have anything to use, we return
 everything back due to "man strchr":
 "so that if c is specified as '\0', these functions 
 return a pointer to the terminator."
 What it means is it supposedly keeps reading till
 the end of the string where '\0' is. Then return
 it at "THAT" point.
*/
//
/*
int	main(void)
{
	char	str_haystack[20] = "Have needle @stack!";
	char	find_needle[20] = "@";

	ft_strchr(str_haystack, find_needle);
	if (ft_strchr(str_haystack, find_needle) != 0)
	{
	printf("We need %s\n", ft_strchr(str_haystack, find_needle));
	}
	else
	{
		printf("Failed to find needle at haystack\n");
	}
	printf("%s",ft_strchr("hel @lo",'@'));
	return (0);
}
*/
// 	if (character == '\0')
//		return ((char *)s + ft_strlen(s)); (to return pointer to
//NULL terminator)*
