/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:35:40 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 19:02:04 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstring;
	unsigned int	index;

	index = 0;
	newstring = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!newstring)
		return (NULL);
	while (index < ft_strlen(s))
	{
		newstring[index] = f(index, s[index]);
		index++;
	}
	newstring[index] = '\0';
	return (newstring);
}
//iterating means repeatedly do operation/get elements
//in a sequence, such as characters in a string or elements
//in an array, one at a time.
//-------------------------------------------------------
//"Return Value":
//The string created from the successive applications
//of ’f’.
//Returns NULL if the allocation fails.
//-------------------------------------------------------
//"Description":
//Applies the function ’f’ to each character of the
//string ’s’, and passing its index as first argument
//to create a new string (with malloc(3)) resulting
//from successive applications of ’f’.
//-------------------------------------------------------
//iterating means repeatedly do operation/get elements
//in a sequence, such as characters in a string or elements
//in an array, one at a time.
//
/*
int	main(void)
{
	char const 	s[] = "HACKAton12345@";
	char		*f;

	printf("Newstring: %s\n",ft_strmapi(s, f));
	return (0);
}
*/
