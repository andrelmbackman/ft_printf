/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:36:53 by abackman          #+#    #+#             */
/*   Updated: 2022/03/30 16:33:03 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	width_helper(const char *format, t_print *p)
{
	int	width;

	width = 0;
	//printf("WIDTH HELPER1\n");
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
		else if (format[p->i] == '*')
			width = va_arg(p->ap, int);
		p->i++;
	}
	//printf("WIDTH HELPER2\n");
	return (width);
}

/*
** If width is specified through the '*' (an argument),
** this will be the width. The exception is if width is specified in the
** format string, the one with the smallest absolute value will be the width.
*/

static void	get_width(const char *format, t_print *p)
{
	int	new_width;

	new_width = width_helper(format, p);
	if (new_width < 0)
	{
		p->minus = 1;
		new_width *= -1;
	}
	while (ft_isdigit((int)format[p->i]) && format[p->i])
		p->width = (p->width * 10) + (format[p->i++] - '0');
	if (new_width && new_width < p->width)
		p->width = new_width;
	//printf("GET_WIDTH FORMAT CHAR: %c i: %i width: %i\n", format[p->i], p->i, p->width);
}

static void	get_prec(const char *format, t_print *p, int save)
{
	int	check_neg;

	check_neg = 0;
	if (format[p->i] != '.')
		return ;
	else
		p->precision = 0;
	p->i++;
	if (format[p->i] == '*')
	{
		save = va_arg(p->ap, int);
		p->i++;
	}
	if (format[p->i] == '-' || save < 0)
		check_neg = 1;
	if (format[p->i] == '-')
		p->i++;
	if (save < 0)
		save *= -1;
	while (ft_isdigit(format[p->i]) && format[p->i])
		p->precision = (p->precision * 10) + (format[p->i++] - '0');
	//printf("GET_PREC: p->i: %i precision: %i\n", p->i, p->precision);
	//while (format[p->i] && !ft_strchr(SPECIFY, format[p->i]))
	//	p->i++;
	if (check_neg)
		p->precision = 0;
	if (save)
		p->precision = save;
}

static void	get_length(const char *format, t_print *p)
{
	while (ft_strchr("hlLz", format[p->i]) && format[p->i])
	{
		if (format[p->i] == 'h')
			p->h++;
		else if (format[p->i] == 'l')
			p->l++;
		else if (format[p->i] == 'L')
			p->L++;
		else if (format[p->i] == 'z')
			p->z++;
		p->i++;
	}
}

int	get_field(const char *format, t_print *print)
{	
	//printf("\nGET_FIELD1: str: \"%s\" char: \"%c\" PREC: %iEND\n", print->str, format[print->i], print->precision);
	get_width(format, print);
	if (format[print->i] == '*')
	{
		print->width = va_arg(print->ap, int);
		print->i++;
	}
	while (format[print->i] && format[print->i] == '*')
		print->i++;
	if (print->minus)
		print->zero = 0;
	//printf("GET_FIELD2: %c PREC: %i i: %i END\n", format[print->i], print->precision, print->i);
	get_prec(format, print, 0);
	//printf("GET_FIELD3: %c PREC: %i i: %i END\n", format[print->i], print->precision, print->i);
	get_length(format, print);
	//printf("GET_FIELD4: %c PREC: %i i: %i END\n", format[print->i], print->precision, print->i);
	return (0);
}
