/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:19:34 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 18:20:41 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str1;
	size_t	str2;
	char	*newstr;

	str1 = 0;
	str2 = 0;
	newstr = (char *)malloc(sizeof(char)
			* ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!newstr)
		return (NULL);
	while (s1[str1] != '\0')
	{
		newstr[str1] = s1[str1];
		str1++;
	}
	while (s2[str2] != '\0')
	{
		newstr[str1 + str2] = s2[str2];
		str2++;
	}
	newstr[str1 + str2] = '\0';
	return (newstr);
}
/*
 "Objective of strjoin":
 Allocates (with malloc(3)) and returns a new
 string, which is the result of the concatenation
 of ’s1’ and ’s2’.

 "Return value"
 The new string, or NULL should allocation fails.

 newstr is the new string, the combined might
 of value s1 & s2. That is why when we malloc,
 we get the total strlen of both s1 & s2 then + 1.

 we then use "while (s1[str1] != '\0')" & 
 "while (s2[str2] != '\0')" to get the combined 
 values.

 After which, we '\0' the last part and return
 the combined string.
*/
//
/*
int	main(void)
{
	char	destination[200] = "Hello ";
	char	source[25] = "World";
	
	printf("The words combines into: '%s'\n", ft_strjoin(destination, source));
}
*/
