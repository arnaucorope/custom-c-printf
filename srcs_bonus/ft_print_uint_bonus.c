/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin@student.42barcelona.com           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:37:38 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/27 18:04:04 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_unsigned_len(unsigned int nb, t_format *fmt)
{
	int	count;

	if (fmt->dot && fmt->precision == 0 && nb == 0)
		return (0);
	count = 1;
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static int	ft_putunbr_bonus(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += ft_putunbr_bonus(nb / 10);
	count += ft_putchar_pf((nb % 10) + '0');
	return (count);
}

int	ft_print_uint_bonus(unsigned int nb, t_format *fmt)
{
	int		len;
	int		prec_zeros;
	int		padding;
	int		count;
	char	pad;

	count = 0;
	len = get_unsigned_len(nb, fmt);
	prec_zeros = get_int_precision(len, fmt);
	padding = get_width_padding(len + prec_zeros, fmt);
	pad = get_char_pad(fmt);
	if (!fmt->minus && pad == ' ')
		count += ft_print_padding(padding, pad);
	if (!fmt->minus && pad == '0')
		count += ft_print_padding(padding, '0');
	count += ft_print_padding(prec_zeros, '0');
	if (len > 0)
		count += ft_putunbr_bonus(nb);
	if (fmt->minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}
