/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:52:31 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/19 17:51:19 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_format
{
	int		minus;
	int		zero;
	int		width;
	int		dot;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	char	type;
}	t_format;

int		ft_printf(char const *str, ...);
int		ft_putchar_pf(int c);
int		ft_putstr_pf(char *str);
int		ft_putnbr_pf(int nb);
int		ft_putunbr_pf(unsigned int nb);
int		ft_puthex_pf(unsigned int nb, char c);
int		ft_putptr_pf(void *ptr);
void	ft_init_format(t_format *fmt);
void	ft_parse_format(char const *str, int *i, t_format *fmt);

#endif
