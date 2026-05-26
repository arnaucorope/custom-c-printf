/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:11:25 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/20 14:11:49 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_padding(int size, char c)
{
    int count;

    count = 0;
    while (count < size)
        count += ft_putchar_pf(c);
    return (count);
}

