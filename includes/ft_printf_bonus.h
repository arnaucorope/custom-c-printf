/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 12:52:31 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/28 11:28:44 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include "ft_printf.h"

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

void	ft_init_format(t_format *fmt);
void	ft_parse_format(char const *str, int *i, t_format *fmt);

int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		ft_print_padding(int size, char c);
int		get_width_padding(int tlen, t_format *fmt);
char	get_char_pad(t_format *fmt);

int		ft_print_int_bonus(int nb, t_format *fmt);
int		get_int_precision(int len, t_format *fmt);
int		get_int_len(int nb, t_format *fmt);
int		get_int_sign(int nb, t_format *fmt);

int		ft_print_uint_bonus(unsigned int nb, t_format *fmt);
int		ft_print_hex_bonus(unsigned int nb, t_format *fmt, char c);
int		ft_print_char_bonus(int c, t_format *fmt);
int		ft_print_percent_bonus(t_format *fmt);
int		ft_print_str_bonus(char *str, t_format *fmt);
int		ft_print_ptr_bonus(void *ptr, t_format *fmt);

#endif
