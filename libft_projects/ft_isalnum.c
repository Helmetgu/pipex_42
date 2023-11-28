/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:21:05 by mlow              #+#    #+#             */
/*   Updated: 2023/09/22 16:13:42 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
// Refer to each function.
//
//ft_isalpha(c)
//The values returned are "nonzero" if the character c falls 
// into the "tested class(a-z & A-Z)", "and zero if not".
//
//ft_isdigit(c)
// checks for a digit (0 through 9).
