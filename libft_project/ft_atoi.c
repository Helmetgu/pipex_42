/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:49:28 by mlow              #+#    #+#             */
/*   Updated: 2023/09/22 15:22:27 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	minus;
	int	i;

	num = 0;
	minus = 1;
	i = 0;
	while ((nptr[num] >= '\t' && nptr[num] <= '\r') || nptr[num] == ' ')
		num++;
	if (nptr[num] == '-' || nptr[num] == '+') 
	{
		if (nptr[num] == '-')
			minus = minus * -1;
		num++;
	}
	while (nptr[num] >= '0' && nptr[num] <= '9')
	{
		i = (i * 10) + (nptr[num] - '0');
		num++;
	}
	return (i * minus);
}
/*
int	main(void)
{
	char	str[] = "   +1234ab567";
	char	strr[] = "   ++1234ab567";
	char	strr1[] = "   -1234ab567";
	char	strr2[] = "   --1234ab567";
	char	strr3[] = "   1234ab567";
	char	strr4[] = "1234ab567";

	printf("The value we should read is: %d\n", ft_atoi(str));
	printf("The value we should read is: %d\n", ft_atoi(strr));
	printf("The value we should read is: %d\n", ft_atoi(strr1));
	printf("The value we should read is: %d\n", ft_atoi(strr2));
	printf("The value we should read is: %d\n", ft_atoi(strr3));
	printf("The value we should read is: %d\n", ft_atoi(strr4));
	
}
*/
//
/*
"Objective" of ft_atoi is to convert the initial 
 portion of the string pointed to by nptr to int.

Following the "man strtol(nptr, NULL, 10)" as atoi
 is following from, atoi is different from the 
 piscine version. The piscine version reads and
 handles "1 or more '+' or '-'" symbols. However,
 the correct way to do atoi is to read "ONLY 1"
 of either "'+' or '-'" sign. Should there be
 more than 1, the function terminates.

With this logic, my function has "int num, minus"
 will handle the signs while the "int i" handles
 the value of coverting "char characters" from
 "0 - 9".

"((nptr[num] >= '\t' && nptr[num] <= '\r') || nptr[num] == ' ')"
 is responsible for skipping whitespace characters
 '\t' (horizontal tab)
 '\n' (new line)
 '\v' (vertical tab)
 '\f' (form feed)
 '\r' (carriage ret)
 ' '  (Space/ 32)
 the num++; just move things along while it is true.

"if (nptr[num] == '-' || nptr[num] == '+')"
 This reads once if that was "'-' or '+'" sign.
 if it is "'-'" it will give a minus 1 value.

"i = (i * 10) + (nptr[num] - '0')" This part of
 code inside of the loop handles/update the 
 value of "i" which is the final int value.
 If u are still not sure how it works refer
 to the below.
	
 Suppose we have the input string "123",
 i = 0 because we havent start yet.
 -nptr[num] is '1', which is the first character 
of the input string.
 -(nptr[num] - '0') is equivalent to 1 because we 
subtract the ASCII value of '0' from the ASCII value of '1'.
 i = (0 * 10) + 1
 i = 0 + 1
 i = 1

 now when num is 2.
 -nptr[num] is '2', the second character.
 -(nptr[num] - '0') is 2.
 i = (1 * 10) + 2
 i = 10 + 2
 i = 12

 Finally, when num is 3.
 -nptr[num] is '3', the third character.
 -(nptr[num] - '0') is 3.
 i = (12 * 10) + 3
 i = 120 + 3
 i = 123

The "return (i * minus)" is when the loop ends,
 we store the value "i" and minus is there if
 we need to account for negative value. Thus
 return negative if there is a minus sign and
 positive if no sign at all.

*/
//done minus and pluses, track odd or even number of -ses
//done if it is a odd number, change sign to -
// return individual number
// ensure that only one '-' or '+'. man strtoll for reference.
