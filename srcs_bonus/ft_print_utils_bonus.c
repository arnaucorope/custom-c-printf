/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin@student.42barcelona.com           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 11:34:48 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/27 17:23:40 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	get_int_precision(int len, t_format *fmt)
{
	if (fmt->dot && fmt->precision > len)
		return (fmt->precision - len);
	return (0);
}

int	get_width_padding(int tlen, t_format *fmt)
{
	if (tlen < fmt->width)
		return (fmt->width - tlen);
	return (0);
}

char	get_char_pad(t_format *fmt)
{
	if (!fmt->minus && fmt->zero && !fmt->dot)
		return ('0');
	return (' ');
}

int	get_int_len(int nb, t_format *fmt)
{
	int		count;
	long	number;

	if (fmt->dot && fmt->precision == 0 && nb == 0)
		return (0);
	number = (long)nb;
	count = 1;
	if (number < 0)
		number = -number;
	while (number > 9)
	{
		number /= 10;
		count++;
	}
	return (count);
}

int	get_int_sign(int nb, t_format *fmt)
{
	if (nb < 0)
		return (1);
	if (fmt->plus)
		return (1);
	if (fmt->space)
		return (1);
	return (0);
}
