/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:28:07 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/27 21:57:13 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_select_type(va_list args, t_format *fmt)
{
	int	count;

	count = 0;
	if (fmt->type == 'c')
		count += ft_print_char_bonus(va_arg(args, int), fmt);
	else if (fmt->type == 's')
		count += ft_print_str_bonus(va_arg(args, char *), fmt);
	else if (fmt->type == '%')
		count += ft_print_percent_bonus(fmt);
	else if (fmt->type == 'i' || fmt->type == 'd')
		count += ft_print_int_bonus(va_arg(args, int), fmt);
	else if (fmt->type == 'u')
		count += ft_print_uint_bonus(va_arg(args, unsigned int), fmt);
	else if (fmt->type == 'x' || fmt->type == 'X')
		count += ft_print_hex_bonus(va_arg(args, unsigned int), fmt, fmt->type);
	else if (fmt->type == 'p')
		count += ft_print_ptr_bonus(va_arg(args, void *), fmt);
	else
	{
		count += ft_putchar_pf('%');
		count += ft_putchar_pf(fmt->type);
	}
	return (count);
}

static int	ft_handle_format(char const *str, int *i, va_list args)
{
	t_format	fmt;
	int			count;

	count = 0;
	ft_init_format(&fmt);
	ft_parse_format(str, i, &fmt);
	count += ft_select_type(args, &fmt);
	(*i)++;
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
			count += ft_handle_format(str, &i, args);
		else
		{
			count += ft_putchar_pf(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}
