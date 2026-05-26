/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:38:59 by acoromin          #+#    #+#             */
/*   Updated: 2026/04/22 10:27:49 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_nlen(long n)
{
	if (n < 0)
		return (1 + ft_nlen(-n));
	if (n < 10)
		return (1);
	return (1 + ft_nlen(n / 10));
}

char	*ft_itoa(int n)
{
	char	*nb;
	size_t	len;
	long	nbr;

	nbr = (long)n;
	len = ft_nlen(nbr);
	nb = malloc(len + 1);
	if (!nb)
		return (NULL);
	nb[len--] = '\0';
	if (nbr < 0)
	{
		nbr = -nbr;
		nb[0] = '-';
	}
	if (nbr == 0)
		nb[0] = '0';
	while (nbr > 0)
	{
		nb[len--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (nb);
}
/*
int	main (int ac, char **av)
{
	if (ac == 2)
		printf("%s\n", ft_itoa(atoi(av[1])));
	return (0);
}*/
