/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:06:02 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/17 18:21:58 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_pf(unsigned int nb, char c)
{
	int	count;

	count = 0;
	if (nb >= 16)
		count += ft_puthex_pf(nb / 16, c);
	if (c == 'x')
		count += ft_putchar_pf("0123456789abcdef"[nb % 16]);
	else if (c == 'X')
		count += ft_putchar_pf("0123456789ABCDEF"[nb % 16]);
	return (count);
}

static int	ft_puthlong_pf(unsigned long nbr)
{
	int	count;

	count = 0;
	if (nbr >= 16)
		count += ft_puthlong_pf(nbr / 16);
	count += ft_putchar_pf("0123456789abcdef"[nbr % 16]);
	return (count);
}

int	ft_putptr_pf(void *ptr)
{
	int				count;
	unsigned long	nbr;

	if (!ptr)
		return (ft_putstr_pf("(nil)"));
	nbr = (unsigned long)ptr;
	count = 0;
	count += ft_putstr_pf("0x");
	count += ft_puthlong_pf(nbr);
	return (count);
}
