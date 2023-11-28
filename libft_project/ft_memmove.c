/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:31:24 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 16:00:38 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*di;
	unsigned char	*si;

	di = (unsigned char *)dest;
	si = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	if (di > si)
		while (n-- > 0)
			di[n] = si[n];
	else
	{
		while (n != 0)
		{
			*di++ = *si++;
			n--;
		}
	}
	return (dest);
}
/*
 "Objective of memmove":
 copies n bytes from memory area src to memory area dest
 The memory areas may over‐lap: copying takes place as 
 though the bytes in src are first copied into a temporary 
 array that does not overlap src or dest, and the bytes are 
 then copied from the temporary array to dest.

By changing the values of const void into unsigned char,
 we can then check the values. Should dest and src
 are "NULL", return value of that dest(NULL).

"if (di > si)" checks if di starts after si memory address 
 in memory. This determines which copying should occur. 
 This one occurs if di is higher in memory address than
 si(source) data.
 "while (n-- > 0)" ("*remember, size vs array index[0], thus n--")
 if di comes after source, the loop is used. It copies memory 
 contents from the "end" of source to the "end" of the 
 destination. They are copied in reverse order.

"else" "while (n != 0)" means that the memory overlaps
 with the source. This occurs when destination(di) comes
 before source(si), which bascially means di starts before
 si.

e.g: source = dst("is")
	dst = Learni"n"gisfun
ft_memmove(dst + 6, dst + 0, 10);

 should "else" be true, we start from beginning and add
 till size_t n fails.

 "Q1") Should i have did *di = '\0; &&
 return (di) instead?
 -no because the "man memmove" never asked us to null.
 Just required to copy src over to dest.
 "Q2") Why am i returning dest instead of di?
 While it is due to the "man memmove". It is also because
 di is bascially you putting (unsigned char *) dest
 all over the place, which means dest is affected and 
 dest value changed along while you used di.

 Return (dest).

-"from memcpy"-
*The difference between this and memmove is that
 if you tried to copy a value with src and that src
 actually took its value from dest, what happens is that
 eventually when the src tries to change the value that
 it is pointing to: E.g: 1"23"45-> 1"22"22.
memmove however, will not have this issue as it will create
a temporary buffer that has the values of src unaffected
by anything which will then send over to dest.
*/
//
/*
if (di > si) checks if the di address is > si address.
		while (n-- > 0)
			di[n] = si[n];
int	main(void) 
{
    char str[30] = "Learningisfun";
    char *first, *second;
    first = str;
    second = str;
    printf("Original string :%s\n ", str);
      
     when overlap happens then it just ignore it
    memcpy(first + 8, first, 10);
    printf("memcpy overlap : %s\n ", str);
  
     when overlap it start from first position
    ft_memmove(second + 8, first, 10);
    printf("memmove overlap : %s\n ", str);
  
    return 0;
 
    	char dest[]= "lorem ipum dolor sit a";
	char src[] = "lorem";
	

	if (dest != ft_memmove(dest, src, 8))
	write(1, "dest's adress was not returned\n", 31);
	write(1, dest, 22);

	printf("Before memmove: desc= %s\n", (void *)dest);
	printf("After memmove: desc= %s\n", ft_memmove((void *)dest, src, 1));
	printf("memmove test: %s\n", memmove((void *)dest, src , 1));
	return 0;
}*/
