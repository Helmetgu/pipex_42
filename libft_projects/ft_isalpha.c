/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:43:11 by mlow              #+#    #+#             */
/*   Updated: 2023/09/22 16:19:35 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (c);
	return (0);
}
/*
 "Objective of isalpha":
 check whether c, which must have the value of an unsigned char
 falls into a certain character class.

Checks for an alphabetic character; in the standard "C" locale.
it is equivalent to (isupper(c) || is‐lower(c))

The values returned are "nonzero" if the character c falls 
into the "tested class(a-z & A-Z)", "and zero if not".
*/
