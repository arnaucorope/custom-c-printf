/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:28:07 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/17 16:50:20 by acoro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_format(va_list args, char const c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_pf(va_arg(args, int));
	else if (c == 's')
		count += ft_putstr_pf(va_arg(args, char *));
	else if (c == '%')
		count += ft_putchar_pf('%');
	else if (c == 'i' || c == 'd')
		count += ft_putnbr_pf(va_arg(args, int));
	else if (c == 'u')
		count += ft_putunbr_pf(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex_pf(va_arg(args, unsigned int), c);
	else if (c == 'p')
		count += ft_putptr_pf(va_arg(args, void *));
	else
	{
		count += ft_putchar_pf('%');
		count += ft_putchar_pf(c);
	}
	return (count);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			count += ft_select_format(args, str[i + 1]);
			i += 2;
		}
		else
		{
			count += ft_putchar_pf(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
