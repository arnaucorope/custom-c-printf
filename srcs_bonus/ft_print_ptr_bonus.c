/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin@student.42barcelona.com           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 21:51:18 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/28 10:46:09 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_ptr_len(unsigned long nb)
{
	int	count;

	count = 1;
	while (nb >= 16)
	{
		nb /= 16;
		count++;
	}
	return (count);
}

static int	ft_putptr_hex(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_putptr_hex(nb / 16);
	count += ft_putchar_pf("0123456789abcdef"[nb % 16]);
	return (count);
}

static int	ft_print_nil(t_format *fmt)
{
	int	count;
	int	padding;

	count = 0;
	padding = get_width_padding(5, fmt);
	if (!fmt->minus)
		count += ft_print_padding(padding, ' ');
	count += ft_putstr_pf("(nil)");
	if (fmt->minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}

int	ft_print_ptr_bonus(void *ptr, t_format *fmt)
{
	unsigned long	address;
	int				len;
	int				padding;
	int				count;

	count = 0;
	if (!ptr)
		return (ft_print_nil(fmt));
	address = (unsigned long)ptr;
	len = get_ptr_len(address) + 2;
	padding = get_width_padding(len, fmt);
	if (!fmt->minus)
		count += ft_print_padding(padding, ' ');
	count += ft_putstr_pf("0x");
	count += ft_putptr_hex(address);
	if (fmt->minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}
