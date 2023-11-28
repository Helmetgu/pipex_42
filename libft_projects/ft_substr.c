/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:48:25 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 21:36:09 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	num_s;
	size_t	num_st;
	char	*substring;

	num_s = 0;
	num_st = (size_t)start;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (s[num_s + num_st] && (num_s < len))
	{
		substring[num_s] = s[num_s + num_st];
		num_s++;
	}
	substring[num_s] = '\0';
	return (substring);
}
/*
 "Objective of substr":
 Allocates (with malloc(3)) and returns a 
 substring from the string ’s’. The substring 
 begins at index ’start’ and is of maximum size ’len’.

"Parameters":
 s: The string from which to create the substring.
 start: The start index of the substring in the string ’s’.
 len: The maximum length of the substring.

 "Return Value":
 The substring.
 NULL if the allocation fails.

 if "s" is empty string, NULL.
 Start is the start index, if it is more than or equal
 to total length of "s", return (""). an empty string.
This usually don't happen cause we dont start for 
 shit after the damn strings past null.
Cannot NULL because we need to return "substring".

Should len be more than length of "s" - start, 
 we give len the highest value possible which
 is basically "length of s - start" cause that is all
 the len left.

After securing the value of len, we malloc with 
 substring, then we start pumping value of "s" into
 substring starting at the start index.

After that, we '\0' it and return value~.

const char = cannot change anything inside/ can change pointer location
 char const = can change anything inside/ cannot change pointer location
 */
//
/*
int	main(void)
{
	char const vs[] = "Hello world and every nyanQ@#*&~!!!!";
	unsigned int start;
	size_t	length;

	start = 200;
	length = 10;
	printf("Starting value: %s\n", vs);
	printf("Value obtained after ft_substr: %s\n", ft_substr(vs, start, length));
	return (0);
}
*/
