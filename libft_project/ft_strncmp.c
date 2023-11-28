/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:17:20 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 19:55:10 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			num;
	unsigned char	*ss1;
	unsigned char	*ss2;

	num = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while ((ss1[num] != '\0' || ss2[num] != '\0') && num < n)
	{
		if (ss1[num] == ss2[num])
			num++;
		else
			return (ss1[num] - ss2[num]);
	}
	return (0);
}
/*
 "Objective of strncmp":
 return an integer less than, equal to, or greater than zero.
 So it is s1 vs s2.

 It is like strcmp except now size_t n is in the mix.
 we need to convert into unsigned char * as we need to do
 working.
"while ((ss1[num] != '\0' || ss2[num] != '\0') && num < n)"
 This part of the code, what it does is that it checks
 if either ss1 or ss2 are "NULL", if only either of them
 are '\0' (if one is '\0' but the other isnt), & if num 
 is still lesser than n, it will run the while loop.

 The sentence above handled what happens if s1 or s2 are 
 "NULL". So don't worry. This code is correct.
 */
//
/*
int	main(void)
{
	size_t		number = 5;
	const char		s1[5] = "ABC";
	const char		s2[5] = "ABCD";

	if (ft_strncmp(s1, s2, number) == 0)
	{
		printf("s1 and s2 are equal");
	}
	else if (ft_strncmp(s1, s2, number) > 0)
	{
		printf("s1 is more than s2");
	}
	else if (ft_strncmp(s1, s2, number) < 0)
	{
		printf("s1 is less than s2");
	}
	return(0);
}
*/
