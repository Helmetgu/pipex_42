/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:27:23 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 18:12:25 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*dest;
	size_t		i;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
 "Objective of strdup":
 returns a pointer to a new string which is a duplicate of the string "s".
 It returns  NULL  if  insufficient memory was available, with errno 
 set to indicate the cause of the error.
 
We first get the malloc space with strlen for "s". Then we copy value
 from "s" into dest. Once that is done, '\0' the last index and return
 the full string of dest.
*/
// you dont need to typecast (ft_strdup(source) as it is already char
// malloc (nmemb * size);
// -returns a pointer to allocated memory (probably dest)
// --free() frees memory space pointed to by ptr,
// --returned by a previous call to malloc.
/*
int	main(void)
{
	const char	source[25] = "Copying over?";
	char	*dest = (ft_strdup(source));

	printf("Copied over: %s\n", dest);
	free(dest);
	return (0);
}
*/
