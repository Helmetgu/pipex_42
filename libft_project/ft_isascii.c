/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:13:22 by mlow              #+#    #+#             */
/*   Updated: 2023/09/22 16:38:08 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
 "Objective of isascii":
 check whether c, which must have the value of an unsigned char
 falls into a certain character class.

Checks for an alphabetic character; in the standard "C" locale.
 it is equivalent to (isupper(c) || is‐lower(c))

checks whether c is a 7-bit unsigned char value that fits into 
 the ASCII character set.
 -ASCII is a 7-bit code - 127
 - unsigned is 255. (8 bit)
*/
