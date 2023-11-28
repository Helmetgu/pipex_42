/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:36:06 by mlow              #+#    #+#             */
/*   Updated: 2023/09/23 16:21:33 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		nb;
	char	s;

	nb = n;
	if (nb == 0)
	{
		write (fd, "0", 1);
		return ;
	}
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd((nb / 10), fd);
	}
	s = (nb % 10) + '0';
	write(fd, &s, 1);
}
//Parameters:
//n: The integer to output.
//fd: The file descriptor on which to write.
//
//Description
//Outputs the integer ’n’ to the given file descriptor
//shawn was helpful!
/*
 "Objective of putnbr_fd":
 Works like the piscine putnbr: just remember how
 divide(/) and modulos(%) works.
"If n == 0" write char "0",
"If nb == -2147483648" write char "-2147483648" and 11.
"If nb < 0" write the '-' sign then go to the positive
 side after doing * -1 to your work.
"If nb > 9" to write, get the most right side of the
 char by dividing(/) by 10. call back the function 
 till all of the nb(n) are read.

 e.g: 12345
 ft_putnbr_fd -> 12345, 1234, 123, 12, 1.

 1 will go through "s = (nb % 10) + '0'" first,
 and then output by write, 
 followed by 12 which will go through 
 "s = (nb % 10) + '0'" and then output by write.
 This will be done until 12345 is outputted.
 */
