/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:36:53 by abackman          #+#    #+#             */
/*   Updated: 2022/03/09 15:03:54 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_struct(t_print *print)
{
	print->len = 0;
	print->width = 0;
	print->precision = 0;
	print->hash = 0;
	print->zero = 0;
	print->space = 0;
	print->upper = 0;
	print->plus = 0;
	print->f_char = 0;
	print->length = 0;
}

static void	get_length(const char *format, t_print *print)
{

}


static void	get_prec(const char *format, t_print *print)
{
	
}

int	get_field(const char *format, t_print *print)
{
	int	i;

	i = 0;
	init_struct(print);
	if (format[i] == '0')
		print->f_char = '0';
	else if (format[i] == ' ')
		print->f_char = ' ';
	i++;
	while (ft_isdigit(*format))
		i = (i * 10) + (*format++ - '0');
	print->width = i;
}
