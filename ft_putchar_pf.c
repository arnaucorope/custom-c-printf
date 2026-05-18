/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:56:31 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/17 18:14:46 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pf(int c)
{
	char	ch;

	ch = (char)c;
	write(1, &ch, 1);
	return (1);
}

int	ft_putstr_pf(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr_pf("(null)"));
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}
