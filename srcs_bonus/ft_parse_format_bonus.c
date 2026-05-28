/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoromin <acoromin@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:28:07 by acoromin          #+#    #+#             */
/*   Updated: 2026/05/19 18:01:07 by acoromin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_parse_flags(char const *str, int *i, t_format *fmt)
{
	while (str[*i] == '-' || str[*i] == '0'
		|| str[*i] == '#' || str[*i] == ' ' || str[*i] == '+')
	{
		if (str[*i] == '-')
			fmt->minus = 1;
		else if (str[*i] == '0')
			fmt->zero = 1;
		else if (str[*i] == '#')
			fmt->hash = 1;
		else if (str[*i] == ' ')
			fmt->space = 1;
		else if (str[*i] == '+')
			fmt->plus = 1;
		(*i)++;
	}
}

static void	ft_parse_width(char const *str, int *i, t_format *fmt)
{
	if (ft_isdigit(str[*i]))
	{
		fmt->width = ft_atoi(&str[*i]);
		while (ft_isdigit(str[*i]))
			(*i)++;
	}
}

static void	ft_parse_precision(char const *str, int *i, t_format *fmt)
{
	if (str[*i] == '.')
	{
		fmt->dot = 1;
		(*i)++;
		fmt->precision = ft_atoi(&str[*i]);
		while (ft_isdigit(str[*i]))
			(*i)++;
	}
}

void	ft_init_format(t_format *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->width = 0;
	fmt->dot = 0;
	fmt->precision = 0;
	fmt->hash = 0;
	fmt->space = 0;
	fmt->plus = 0;
	fmt->type = 0;
}

void	ft_parse_format(char const *str, int *i, t_format *fmt)
{
	(*i)++;
	ft_parse_flags(str, i, fmt);
	ft_parse_width(str, i, fmt);
	ft_parse_precision(str, i, fmt);
	fmt->type = str[*i];
}
