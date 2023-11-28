/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:01:39 by mlow              #+#    #+#             */
/*   Updated: 2023/09/06 17:53:37 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	length_so_far;

	length_so_far = 0;
	while (s[length_so_far] != '\0')
	{
		length_so_far++;
	}
	return (length_so_far);
}
