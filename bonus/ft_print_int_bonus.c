/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:22:42 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/22 18:25:02 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_int_precision(int len, t_format *fmt)
{
	if (fmt->dot && fmt->precision > len)
		return (fmt->precision - len);
	return (0);
}

int	get_int_width(int tlen, t_format *fmt)
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

int	ft_print_int_bonus(int nb, t_format *fmt)
{
	int		len;
	int		prec_zeros;
	int		padding;
	int		count;
	char	pad;

	count = 0;
	len = get_int_len(nb, fmt);
	prec_zeros = get_int_precision(len, fmt);
	padding = get_int_width(len + prec_zeros, fmt);
	pad = get_char_pad(fmt);
	if (!fmt->minus)
		count += ft_print_padding(padding, pad);
	count += ft_print_padding(prec_zeros, '0');
	count += ft_putnbr_pf(nb);
	if (fmt->minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}
