/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:28:07 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/17 18:51:44 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_select_type(va_list args, t_format *fmt)
{
	int	count;

	count = 0;
	if (fmt->type == 'c')
		count += ft_putchar_pf(va_arg(args, int));
	else if (fmt->type == 's')
		count += ft_putstr_pf(va_arg(args, char *));
	else if (fmt->type == '%')
		count += ft_putchar_pf('%');
	else if (fmt->type == 'i' || fmt->type == 'd')
		count += ft_putnbr_pf(va_arg(args, int));
	else if (fmt->type == 'u')
		count += ft_putunbr_pf(va_arg(args, unsigned int));
	else if (fmt->type == 'x' || fmt->type == 'X')
		count += ft_puthex_pf(va_arg(args, unsigned int), fmt->type);
	else if (fmt->type == 'p')
		count += ft_putptr_pf(va_arg(args, void *));
	else
	{
		count += ft_putchar_pf('%');
		count += ft_putchar_pf(fmt->type);
	}
	return (count);
}

int	ft_printf(char const *str, ...)
{
	int			i;
	int			count;
	va_list		args;
	t_format	fmt;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			ft_init_format(&fmt);
			ft_parse_format(str, &i, &fmt);
			count += ft_select_type(args, &fmt);
			i++;
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
