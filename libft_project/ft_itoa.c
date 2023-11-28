/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:12:21 by mlow              #+#    #+#             */
/*   Updated: 2023/09/22 18:05:37 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_int(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count++; 
		n = n * -1;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str_int; 
	long	nb; 
	int		len; 

	nb = n;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = count_int(n);
	str_int = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_int)
		return (NULL);
	if (nb < 0)
	{
		str_int[0] = '-';
		nb = nb * -1;
	}
	while (len && str_int[len - 1] != '-')
	{
		str_int[len - 1] = (char)(nb % 10 + '0');
		nb = nb / 10;
		len--;
	}
	str_int[count_int(n)] = '\0';
	return (str_int);
}
/*
 "Objective of itoa":
 Return value: 
The string representing the integer.
 NULL if the allocation fails.
Description:
Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.

static int count_int(int n)
Purpose of this static function is to count the
 integers. For the length of string.
 This is done by the following:
 1) "n == 0"
 2) "n < 0"
 3) "n > 0"
 converting the value of int that is given.

"The modulo operator %" will give the remainder
 that is left over when one number is divided by 
 another.
"Division" eg: 5/2 = 2.

 "n == 0"
This one basically returns value "true/ 1" if
 n is 0. This will then be part of malloc, 
 length of 0 & '\0' is 2. 

"n < 0"
This one basically handles the negative: 
 count once for '-' sign and then * -1 to it.
 This will cause the value to become positive
 so that it can go through "while (n > 0)".

"n > 0"
It will count and divide till the while loop
fails. Then it will return the total count.

"char *str_int" cause that is what to return.
 I used "long nb" to handle the -2147483648. But
 it doesnt work. Its bascially int but very long.
 "int len" to count size of str_int from
 static int count_int.


While "length is true".
 (we dont need to worry about str_int[len - 1]
 as 0 will never be minus), it will be converted
 to a char and then "%" till leftover value.
 e.g: 12345 % 10 = 5
Then after which will go through nb = nb / 10.
 e.g: 12345 / 10 = 1234.
This will repeat till all is read.
Or in this case: till len = 0 after len--
or till hit '-' sign then stop while loop.

Finally, Null last index and then return str_int.
*/
