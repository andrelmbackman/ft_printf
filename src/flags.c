/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:36:53 by abackman          #+#    #+#             */
/*   Updated: 2022/03/09 11:15:18 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	init_struct(t_print *print)
{
	print->len = 0;
	print->width = 0;
	print->precision = 0;
	print->hash = 0;
	print->zero = 0;
	print->space = 0;
	print->upper = 0;
	print->f_char = 0;
	print->length = 0;
}
/*
void	get_field(const char *format, t_print *print)
{
	int	i;

	i = 0;
	if (*format == '0')
	{
		print->f_char = '0';
		*format++;
	}
	while (ft_isdigit(*format))
		i = (i * 10) + (*format++ - '0');
	print->width = i;
}
*/