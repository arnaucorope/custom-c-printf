/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 12:22:42 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/27 17:27:48 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_long(long number)
{
	int	count;

	count = 0;
	if (number > 9)
		count += ft_putnbr_long(number / 10);
	count += ft_putchar_pf((number % 10) + '0');
	return (count);
}

static int	ft_putnbr_abs(int nb)
{
	long	number;

	number = (long)nb;
	if (number < 0)
		number = -number;
	return (ft_putnbr_long(number));
}

static int	ft_print_sign(int nb, t_format *fmt)
{
	if (nb < 0)
		return (ft_putchar_pf('-'));
	if (fmt->plus)
		return (ft_putchar_pf('+'));
	if (fmt->space)
		return (ft_putchar_pf(' '));
	return (0);
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
	padding = get_int_width(get_int_sign(nb, fmt) + len + prec_zeros, fmt);
	pad = get_char_pad(fmt);
	if (!fmt->minus && pad == ' ')
		count += ft_print_padding(padding, pad);
	count += ft_print_sign(nb, fmt);
	if (!fmt->minus && pad == '0')
		count += ft_print_padding(padding, '0');
	count += ft_print_padding(prec_zeros, '0');
	if (len > 0)
		count += ft_putnbr_abs(nb);
	if (fmt->minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}
