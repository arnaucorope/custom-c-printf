/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin@student.42barcelona.com           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 18:22:28 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/27 19:08:06 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	gethex_len(unsigned int nb, t_format *fmt)
{
	int	count;

	if (fmt->dot && fmt->precision == 0 && nb == 0)
		return (0);
	count = 1;
	while (nb >= 16)
	{
		count++;
		nb /= 16;
	}
	return (count);
}

static int	get_hash(unsigned int nb, t_format *fmt)
{
	if (fmt->hash && nb != 0)
		return (2);
	return (0);
}

static int	ft_puthex_bonus(unsigned int nb, char c)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_puthex_bonus(nb / 16, c);
	if (c == 'x')
		count += ft_putchar_pf("0123456789abcdef"[nb % 16]);
	else if (c == 'X')
		count += ft_putchar_pf("0123456789ABCDEF"[nb % 16]);
	return (count);
}

static int	ft_print_hash(t_format *fmt, char c, unsigned int nb)
{
	int	count;

	count = 0;
	if (fmt->hash && nb != 0)
	{
		if (c == 'x')
			count += ft_putstr_pf("0x");
		else if (c == 'X')
			count += ft_putstr_pf("0X");
	}
	return (count);
}

int	ft_print_hex_bonus(unsigned int nb, t_format *fmt, char c)
{
	int		len;
	int		prec_zeros;
	int		padding;
	int		count;
	char	pad;

	count = 0;
	len = gethex_len(nb, fmt);
	prec_zeros = get_int_precision(len, fmt);
	padding = get_width_padding(get_hash(nb, fmt) + len + prec_zeros, fmt);
	pad = get_char_pad(fmt);
	if (!fmt->minus && pad == ' ')
		count += ft_print_padding(padding, pad);
	count += ft_print_hash(fmt, c, nb);
	if (!fmt->minus && pad == '0')
		count += ft_print_padding(padding, '0');
	count += ft_print_padding(prec_zeros, '0');
	if (len > 0)
		count += ft_puthex_bonus(nb, c);
	if (fmt->minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}
