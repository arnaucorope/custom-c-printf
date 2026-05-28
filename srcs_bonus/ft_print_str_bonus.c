/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin@student.42barcelona.com           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:48:37 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/28 10:25:22 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_strlen(char *str, t_format *fmt, int is_null)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (is_null && fmt->dot && fmt->precision < 6)
		return (0);
	if (fmt->dot && fmt->precision < i)
		return (fmt->precision);
	return (i);
}

static int	ft_putnstr(char *str, int len)
{
	int	i;

	i = 0;
	while (str[i] && i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_str_bonus(char *str, t_format *fmt)
{
	int	len;
	int	count;
	int	padding;
	int	is_null;

	count = 0;
	is_null = 0;
	if (!str)
	{
		str = "(null)";
		is_null = 1;
	}
	len = get_strlen(str, fmt, is_null);
	padding = get_width_padding(len, fmt);
	if (!fmt->minus)
		count += ft_print_padding(padding, ' ');
	count += ft_putnstr(str, len);
	if (fmt->minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}
