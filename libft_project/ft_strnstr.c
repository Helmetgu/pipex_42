/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 14:51:01 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 20:56:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	num_b;
	size_t	num_l;

	num_b = 0;
	num_l = 0;
	if (little[num_l] == '\0')
		return ((char *)big);
	while ((big[num_b] && little[num_l]) && num_b < len)
	{
		num_l = 0;
		while (big[num_b + num_l] == little[num_l]
			&& big[num_b + num_l] != '\0' 
			&& (num_b + num_l) < len)
			num_l++;
		if (little[num_l] == '\0')
			return ((char *)big + num_b);
		else
			num_b++;
	}
	return (NULL);
}
/*
 "Objective of strnstr":
 locates the first occurrence of the null-terminated 
 string little in the string big, where not more than 
 len characters are searched.

"Return Values":
 If little is an empty string, big is returned; if 
 little occurs nowhere in big, NULL is returned; 
 otherwise a pointer to the first character of the 
 first occurrence of little is returned.

If little is an empty string, 
 "-if (little[num_l] == '\0')
                return ((char *)big);"
if little occurs nowhere in big,
 "return (NULL)"

"while ((big[num_b] && little[num_l]) && num_b < len)"
 Should this part be true, we will go into a new 
 while loop:
 "while (big[num_b + num_l] == little[num_l] 
 	&& big[num_b + num_l] != '\0'
       	&& (num_b + num_l) < len)"
 Which basically keeps reading as long as 
 big is still equal to litte and havent hit
 '\0' and both num_b & num_l are less than len.
 "num_l" is just used to read once big hits
 little and contiune till little is all read
 or the while loop condition fails.
 "num_b" is what we want, it tells us where big
 start to hit the little which we return value 
 here: 
 "if (little[num_l] == '\0')
			return ((char *)big + num_b);"

Remember, it's purpose is to read from the moment
 little have the same value as big, and reads till
 it hits '\0'.
*/
//
/*
int	main(void)
{
	char haystack[] = "Hello, world!";
	char needle[] = "";
	char *result = ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30);

	printf("result: %s\n", result);
	printf("needles is: %s\n", needle);
	if (result == NULL && needle)
		printf("Little contains null, all of haystack valure returned");
	else if (result != NULL)
	{
		printf("Found '%s' in '%s' at position %ld\n",
			needle, haystack, result - haystack);
	}
	else
	{
		printf("'%s' not found in '%s'\n", needle, haystack);
	}
	printf("Value of ft_strnstr: %s\n", &result[0]);
	return (0);
}
*/
