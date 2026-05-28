/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin@student.42barcelona.com           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 20:10:19 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/27 20:32:20 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char_bonus(int c, t_format *fmt)
{
	int		count;
	int		padding;

	count = 0;
	padding = get_width_padding(1, fmt);
	if (!fmt->minus)
		count += ft_print_padding(padding, ' ');
	count += ft_putchar_pf(c);
	if (fmt->minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}
