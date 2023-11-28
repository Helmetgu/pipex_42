/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:43:18 by mlow              #+#    #+#             */
/*   Updated: 2023/09/22 21:06:38 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				num;
	const unsigned char	*ss1;
	const unsigned char	*ss2;

	ss1 = (const unsigned char *)s1;
	ss2 = (const unsigned char *)s2;
	num = 0;
	while (num < n)
	{
		if (ss1[num] == ss2[num])
		{
			num++;
		}
		else
		{
			return ((int)ss1[num] - (int)ss2[num]);
		}
	}
	return (0);
}
/*
 "Objective of memcmp":
 The memcmp() function compares the first n bytes 
 (each interpreted as unsigned char) of the memory 
 areas s1 and s2.

"Return Value":
The memcmp() function returns an integer less than, 
 equal to, or greater than zero if the first n bytes 
 of s1 is found, respectively, to be less than, 
 to match, or be greater than the first n bytes of s2.
 
For a nonzero return value, the sign is determined by 
 the sign of the difference between the first pair of
 bytes (interpreted as unsigned char) that differ in 
 s1 and s2.
 If n is zero, the return value is zero.

First, we need to change the values of both s1 and s2
 into const unsigned char pointers.("ss1, ss2").
 Both ss1 & ss2 will keep comparing till either
 they both have different value in which they
 will compare value via greater or lesser than, 
 or they ran out of size_t n size.

int	main(void)
{
	size_t		number = 5;
	const char		s1[5] = "ABC";
	const char		s2[5] = "ABCD";

	if (ft_memcmp(&s1[0], &s2[0], number) == 0)
	{
		printf("s1 and s2 are equal");
	}
	else if (ft_memcmp(&s1[0], &s2[0], number) > 0)
	{
		printf("s1 is more than s2");
	}
	else if (ft_memcmp(&s1[0], &s2[0], number) < 0)
	{
		printf("s1 is less than s2");
	}
	return(0);
}
*/
