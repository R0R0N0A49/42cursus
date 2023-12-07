/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:05:52 by trebours          #+#    #+#             */
/*   Updated: 2023/11/17 14:28:29 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_usgd(unsigned int n, int fd, char *charbase)
{
	int	rsl;
	int	base;

	base = ft_strlen(charbase);
	rsl = 0;
	if (n > 9)
		rsl = ft_putnbr_usgd(n / base, fd, charbase);
	rsl += 1;
	n = n % base;
	write (fd, &charbase[n], 1);
	return (rsl);
}

int	ft_putnbr_ll(unsigned long long n, int fd, char *charbase)
{
	int			rsl;
	int			base;
	static int	i;

	if (!n)
	{
		write (fd, "(nil)", 5);
		return (5);
	}
	if (i++ == 0)
		write(fd, "0x", 2);
	base = 16;
	rsl = 2;
	if (n > 15)
		rsl = ft_putnbr_ll(n / base, fd, charbase);
	rsl += 1;
	n = n % base;
	write (fd, &charbase[n], 1);
	i = 0;
	return (rsl);
}

int	ft_putnbr_hex(unsigned int n, int fd, char *charbase)
{
	int	rsl;
	int	base;

	base = ft_strlen(charbase);
	rsl = 0;
	if (n > 15)
		rsl += ft_putnbr_hex(n / base, fd, charbase);
	rsl += 1;
	n = n % base;
	write (fd, &charbase[n], 1);
	return (rsl);
}
