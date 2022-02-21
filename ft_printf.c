/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:30:27 by abackman          #+#    #+#             */
/*   Updated: 2022/02/21 16:25:17 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countargs(const char *format)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
			ret++;
		i++;
	}
	return (ret);
}

static char	*print_ptr(void **ptr)
{

}

static void	get_field(const char *format, t_print *print)
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
	print->f_width = i;
}

static int	checkflag(const char *format, char *buf, t_print *print)
{
	char	*tmp;

	tmp = NULL;
	print->f_width = 0;
	print->f_char = ' ';
	if (ft_isdigit(*format))
		get_field(*format, print);
	if (*format == 'i' || *format == 'd')
		tmp = ft_itoa(print->arg_lst);
	else if (*format == 'c')
		tmp =  ft_getchar(print->arg_lst);
	else if (*format == 'p' || *format == 'P')
		tmp = print_ptr(print->arg_lst);
	if (tmp)
	{
		buf = strjoin_pro(buf, tmp);
		free (tmp);
		return (1);
	}
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	t_print	*print;
	int		i;
	int		ret;

	print->arg_num = countargs(format);
	i = 0;
	ret = 0;
	va_start(print->arg_lst, format);
	print->arg_cur = 0;
	while (*format++)
	{
		if (*format == '%' && (*format - 1) != '%')
			ret += 

		print->arg_cur++;
	}
	va_end(print->arg_lst);
	print->bytes = (int *)ft_strlen(print->buf);
	return (print->bytes);
}