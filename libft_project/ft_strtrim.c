/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:45:47 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 21:20:13 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	str1;
	size_t	start;
	size_t	end;
	char	*trimedstr;

	str1 = 0;
	start = 0;
	if (!s1 || !set)
		return ((char *)s1);
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start])) 
		start++;
	while (s1[end - 1] && ft_strrchr(set, s1[end - 1]) && end > start)
		end--;
	trimedstr = malloc(sizeof(char) * (end - start + 1));
	if (!trimedstr)
		return (NULL);
	while ((start + str1) != end)
	{
		trimedstr[str1] = s1[start + str1];
		str1++;
	}
	trimedstr[str1] = '\0';
	return (trimedstr);
}
/*
 "Objective of strtrim":
 Allocates (with malloc(3)) and returns a copy of
 ’s1’ with the characters specified in ’set’ removed
 from the beginning and the end of the string.

 "Return Value":
 The trimmed string.
 NULL if the allocation fails.

 We start with "if (!s1 || !set)"
 Its to protect us should either have no value.
 We return the orginal string should this happen.

 We get the value of s1 length of string into "end".

"while (s1[start] && ft_strchr(set, s1[start]))"
 Remember, ft_strchr searches for the first occurrence
 of char c in which case, would be the value of
 char const *set. 
 As long as both s1 is not '\0' and s1 can be found
 in the "set" string, start++; will keep occuring.
"Purpose": to skip over any characters at the 
 beginning of the s1 string that are present 
 in the set string.
 it continues until a character is encountered in 
 s1 that is not in the set or "NULL".

"while (s1[end - 1] && ft_strrchr(set, s1[end - 1]) && end > start)"
 Remember, ft_strrchr searches for the first occurence
 but backwards of char. This would be value of 
 s1[end - 1] inside "set" string.
 As long as s1[end - 1] is not '\0' && the value of
 s1 can be found in "set" & end is more than start,
 end--; will keep occuring.
"Purpose": is to skip over any characters at the 
 end of the s1 string that are present in the 
 set string. 
 It continues until a character is encountered in 
 s1 that is not in the set, or until end becomes 
 less than or equal to start. 

Then with trimedstr, we get the size from end - start
 to find that space in between.

We now start at the beginning of that space with values:
 str1.
 Trimedstr will now copy values s1 starting from
 the start of the space in between start & end.

'\0' the last index of trimedstr and return final value.
 */
