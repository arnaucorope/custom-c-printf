/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin@student.42barcelona.com           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:41:17 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/21 22:41:42 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("=== Mandatory ===\n");
	ft_printf("%d\n", 42);
	ft_printf("%s\n", "hola");
	ft_printf("%x\n", 255);
	ft_printf("%%\n");

	printf("\n=== Bonus parser ===\n");

	ft_printf("%8d\n", 42);
	ft_printf("%-8d\n", 42);
	ft_printf("%08d\n", 42);
	ft_printf("%.5d\n", 42);
	ft_printf("%+d\n", 42);
	ft_printf("% d\n", 42);
	ft_printf("%#x\n", 42);

	printf("\n=== Compare libc ===\n");

	printf("%8d\n", 42);
	printf("%-8d\n", 42);
	printf("%08d\n", 42);
	printf("%.5d\n", 42);
	printf("%+d\n", 42);
	printf("% d\n", 42);
	printf("%#x\n", 42);

	return (0);
}
