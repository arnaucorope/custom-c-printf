/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 16:54:08 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/17 18:20:53 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int nb)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = (long)nb;
	if (nbr < 0)
	{
		count += ft_putchar_pf('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		count += ft_putnbr_pf(nbr / 10);
	count += ft_putchar_pf((nbr % 10) + '0');
	return (count);
}

int	ft_putunbr_pf(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += ft_putunbr_pf(nb / 10);
	count += ft_putchar_pf((nb % 10) + '0');
	return (count);
}
