/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:43:09 by trebours          #+#    #+#             */
/*   Updated: 2023/11/04 14:22:36 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd, char *charbase)
{
	int	rsl;
	int	base;

	base = ft_strlen(charbase);
	rsl = 0;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = n * -1;
		write (fd, "-", 1);
		rsl += 1;
	}
	if (n > 9)
		rsl += ft_putnbr_fd(n / base, fd, charbase);
	rsl += 1;
	n = n % base;
	write (fd, &charbase[n], 1);
	return (rsl);
}
