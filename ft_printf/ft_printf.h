/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:04:58 by trebours          #+#    #+#             */
/*   Updated: 2023/11/23 15:50:47 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *src, ...);
int	ft_type(const char src, va_list param);
int	ft_putnbr_usgd(unsigned int n, int fd, char *charbase);
int	ft_putnbr_ll(unsigned long long n, int fd, char *charbase);
int	ft_putnbr_hex(unsigned int n, int fd, char *charbase);

#endif
