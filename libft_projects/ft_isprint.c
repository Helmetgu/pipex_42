/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:12:43 by mlow              #+#    #+#             */
/*   Updated: 2023/09/22 17:20:15 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
 "Objective of isprint":
 check whether c, which must have the value of an unsigned char
 falls into a certain character class.

Checks for an alphabetic character; in the standard "C" locale.
 it is equivalent to (isupper(c) || is‐lower(c))

checks for any "printable character" including "space".
*/
