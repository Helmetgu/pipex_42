/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:40:05 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 18:16:09 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;

	index = 0;
	while (index < ft_strlen(s))
	{
		f(index, &s[index]);
		index++;
	}
}
/*
 "Objective of striteri":
 Applies the function ’f’ on each character of
 the string passed as argument, passing its index
 as first argument. Each character is passed by
 address to ’f’ to be modified if necessary.
*/
//
/*
int	main(void)
{
	printf("value of newstring: %s\n", ft_striteri(s, f));
	return (0);
}
*/
