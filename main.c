/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin@student.42barcelona.com           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 22:41:17 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/27 19:12:56 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	unsigned int	nb;
	unsigned int	max;

	nb = 42;
	max = 4294967295u;

	printf("=== Basic hex ===\n");
	ft_printf("[%x]\n", nb);
	printf("[%x]\n\n", nb);

	ft_printf("[%X]\n", nb);
	printf("[%X]\n\n", nb);

	ft_printf("[%x]\n", max);
	printf("[%x]\n\n", max);

	ft_printf("[%X]\n", max);
	printf("[%X]\n\n", max);

	printf("=== Width ===\n");
	ft_printf("[%8x]\n", nb);
	printf("[%8x]\n\n", nb);

	ft_printf("[%-8x]\n", nb);
	printf("[%-8x]\n\n", nb);

	ft_printf("[%8X]\n", nb);
	printf("[%8X]\n\n", nb);

	printf("=== Zero flag ===\n");
	ft_printf("[%08x]\n", nb);
	printf("[%08x]\n\n", nb);

	ft_printf("[%08X]\n", nb);
	printf("[%08X]\n\n", nb);

	printf("=== Precision ===\n");
	ft_printf("[%.5x]\n", nb);
	printf("[%.5x]\n\n", nb);

	ft_printf("[%.5X]\n", nb);
	printf("[%.5X]\n\n", nb);

	ft_printf("[%.0x]\n", 0);
	printf("[%.0x]\n\n", 0);

	ft_printf("[%5.0x]\n", 0);
	printf("[%5.0x]\n\n", 0);

	ft_printf("[%.3x]\n", 0);
	printf("[%.3x]\n\n", 0);

	printf("=== Width + precision ===\n");
	ft_printf("[%8.5x]\n", nb);
	printf("[%8.5x]\n\n", nb);

	ft_printf("[%-8.5x]\n", nb);
	printf("[%-8.5x]\n\n", nb);

	ft_printf("[%08.5x]\n", nb);
	printf("[%08.5x]\n\n", nb);

	printf("=== Hash ===\n");
	ft_printf("[%#x]\n", nb);
	printf("[%#x]\n\n", nb);

	ft_printf("[%#X]\n", nb);
	printf("[%#X]\n\n", nb);

	ft_printf("[%#x]\n", 0);
	printf("[%#x]\n\n", 0);

	ft_printf("[%#.0x]\n", 0);
	printf("[%#.0x]\n\n", 0);

	printf("=== Hash + width / zero / precision ===\n");
	ft_printf("[%#8x]\n", nb);
	printf("[%#8x]\n\n", nb);

	ft_printf("[%#08x]\n", nb);
	printf("[%#08x]\n\n", nb);

	ft_printf("[%#8.5x]\n", nb);
	printf("[%#8.5x]\n\n", nb);

	ft_printf("[%-#8.5x]\n", nb);
	printf("[%-#8.5x]\n\n", nb);

	ft_printf("[%#08.5x]\n", nb);
	printf("[%#08.5x]\n\n", nb);

	return (0);
}
