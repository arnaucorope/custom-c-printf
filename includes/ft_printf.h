/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin@student.42barcelona.com           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 11:23:33 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/28 11:24:52 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_putchar_pf(int c);
int	ft_putstr_pf(char *str);
int	ft_putnbr_pf(int nb);
int	ft_putunbr_pf(unsigned int nb);
int	ft_puthex_pf(unsigned int nb, char c);
int	ft_putptr_pf(void *ptr);

#endif
