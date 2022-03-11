/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:36:53 by abackman          #+#    #+#             */
/*   Updated: 2022/03/11 17:50:21 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_struct(t_print *print)
{
	print->len = 0;
	print->width = 0;
	print->precision = -1;
	print->hash = 0;
	print->zero = 0;
	print->space = 0;
	print->upper = 0;
	print->plus = 0;
	print->minus = 0;
	print->h = 0;
	print->l = 0;
	print->L = 0;
	print->f_char = 0;
	print->length = 0;
}

static void	get_width(const char *format, t_print *p)
{
	while (ft_strchr("0+- #", format[p->i]))
	{
		if (format[p->i] == '0')
			p->zero = 1;
		else if (format[p->i] == '+')
			p->plus = 1;
		else if (format[p->i] == '-')
			p->minus = 1;
		else if (format[p->i] == ' ')
			p->space = 1;
		else if (format[p->i] == '#')
			p->hash = 1;
		p->i++;
	}
	//printf("\nget_width: %cEND\n", format[p->i]);
	if (p->minus)
		p->zero = 0;
	while (ft_isdigit((int)format[p->i]))
	{
		p->width = (p->width * 10) + (format[p->i] - '0');
		p->i++;
	}
}


static void	get_prec(const char *format, t_print *p)
{
	int	check_neg;

	check_neg = 0;
	if (format[p->i] != '.')
		return ;
	else
		p->precision = 0;
	p->i++;
	if (format[p->i] == '-')
	{
		check_neg = 1;
		p->i++;
	}
	while (ft_isdigit(format[p->i]))
	{
		p->precision = (p->precision * 10) + (format[p->i] - '0');
		p->i++;
	}
	while (format[p->i] && !ft_isalpha(format[p->i]))
		p->i++;
	if (check_neg)
		p->precision = 0;
}

static void	get_length(const char *format, t_print *p)
{
	while (ft_strchr("hlL", format[p->i]))
	{
		if (format[p->i] == 'h')
			p->h++;
		else if (format[p->i] == 'l')
			p->l++;
		else if (format[p->i] == 'L')
			p->L++;
		p->i++;
	}
}

int	get_field(const char *format, t_print *print)
{
	init_struct(print);
	printf("GET_FIELD1: str: \"%s\" char: \"%c\" PREC: %iEND\n", print->str, format[print->i], print->precision);
	get_width(format, print);
	printf("GET_FIELD2: %c PREC: %iEND\n", format[print->i], print->precision);
	get_prec(format, print);
	printf("GET_FIELD3: %c PREC: %iEND\n", format[print->i], print->precision);
	get_length(format, print);
	printf("GET_FIELD4: %c PREC: %iEND\n", format[print->i], print->precision);
	return (0);
}
