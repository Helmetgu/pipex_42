/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:37:22 by mlow              #+#    #+#             */
/*   Updated: 2023/09/22 16:23:17 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	return (0);
}
/*
 "Objective of isdigit":
 check whether c, which must have the value of an unsigned char
 falls into a certain character class.

Checks for an alphabetic character; in the standard "C" locale.
 it is equivalent to (isupper(c) || is‐lower(c))

checks for a digit (0 through 9).
*/
