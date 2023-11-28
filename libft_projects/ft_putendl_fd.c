/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:19:12 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 16:28:32 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
 "Objective of putendl":
 Outputs the string ’s’ to the given file descriptor
 followed by a newline.

"Parameters:"
 s: The string to output.
 fd: The file descriptor on which to write.
 */
