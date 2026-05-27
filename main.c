/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin@student.42barcelona.com           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:41:17 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/27 17:31:30 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
ft_printf("[%+08d]\n", 42);
printf("[%+08d]\n", 42);

ft_printf("[% 08d]\n", 42);
printf("[% 08d]\n", 42);

ft_printf("[%+8.5d]\n", 42);
printf("[%+8.5d]\n", 42);

ft_printf("[%08d]\n", -42);
printf("[%08d]\n", -42);

ft_printf("[%5.0d]\n", 0);
printf("[%5.0d]\n", 0);
	return (0);
}
