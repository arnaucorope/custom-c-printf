/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin@student.42barcelona.com           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:41:17 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/27 18:05:05 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	unsigned int	max;

	max = 4294967295u;

	printf("=== Basic unsigned ===\n");
	ft_printf("[%u]\n", 42);
	printf("[%u]\n\n", 42);

	ft_printf("[%u]\n", 0);
	printf("[%u]\n\n", 0);

	ft_printf("[%u]\n", max);
	printf("[%u]\n\n", max);

	printf("=== Width ===\n");
	ft_printf("[%8u]\n", 42);
	printf("[%8u]\n\n", 42);

	ft_printf("[%-8u]\n", 42);
	printf("[%-8u]\n\n", 42);

	ft_printf("[%1u]\n", 42);
	printf("[%1u]\n\n", 42);

	printf("=== Zero flag ===\n");
	ft_printf("[%08u]\n", 42);
	printf("[%08u]\n\n", 42);

	ft_printf("[%08u]\n", 0);
	printf("[%08u]\n\n", 0);

	printf("=== Precision ===\n");
	ft_printf("[%.5u]\n", 42);
	printf("[%.5u]\n\n", 42);

	ft_printf("[%.1u]\n", 42);
	printf("[%.1u]\n\n", 42);

	ft_printf("[%.0u]\n", 0);
	printf("[%.0u]\n\n", 0);

	ft_printf("[%5.0u]\n", 0);
	printf("[%5.0u]\n\n", 0);

	ft_printf("[%.3u]\n", 0);
	printf("[%.3u]\n\n", 0);

	printf("=== Width + precision ===\n");
	ft_printf("[%8.5u]\n", 42);
	printf("[%8.5u]\n\n", 42);

	ft_printf("[%-8.5u]\n", 42);
	printf("[%-8.5u]\n\n", 42);

	ft_printf("[%08.5u]\n", 42);
	printf("[%08.5u]\n\n", 42);

	ft_printf("[%3.5u]\n", 42);
	printf("[%3.5u]\n\n", 42);

	return (0);
}
