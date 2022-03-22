/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:36:53 by abackman          #+#    #+#             */
/*   Updated: 2022/03/15 18:28:00 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	get_width(const char *format, t_print *p)
{
	while (ft_strchr("0+- #*", format[p->i]))
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
	printf("\nGET_FIELD1: str: \"%s\" char: \"%c\" PREC: %iEND\n", print->str, format[print->i], print->precision);
	get_width(format, print);
	if (format[print->i] == '*')
	{
		print->width = va_arg(print->ap, int);
		print->i++;
	}
	while (format[print->i] && format[print->i] == '*')
		print->i++;
	if (print->width < 0)
	{
		print->minus = 1;
		print-> width *= -1;
	}
	if (print->minus)
		print->zero = 0;
	printf("GET_FIELD2: %c PREC: %iEND\n", format[print->i], print->precision);
	get_prec(format, print);
	printf("GET_FIELD3: %c PREC: %iEND\n", format[print->i], print->precision);
	get_length(format, print);
	printf("GET_FIELD4: %c PREC: %iEND\n", format[print->i], print->precision);
	if (format[print->i] >= 'A' && format[print->i] <= 'Z')
		print->upper = 1;
	return (0);
}
