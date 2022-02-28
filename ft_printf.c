/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:30:27 by abackman          #+#    #+#             */
/*   Updated: 2022/02/28 15:20:04 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
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
	print->width = i;
}

static int	checkflag(const char *format, char *buf, t_print *print)
{
	char	*tmp;

	tmp = NULL;
	print->width = 0;
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
		//buf = strjoin_pro(buf, tmp); function that checks field width too, then strjoins and frees
		free (tmp);
		return (1);
	}
	else
		return (0);
}
*/
static void	ft_prints(int fd, char *str)
{
	if (str && fd >= 0)
		write(fd, str, sizeof(str));
}

int	ft_vasprintf(char *str, const char *format, va_list ap)
{
	t_print	*print;
	int	i;
	int ret;

	i = 0;
	ret = 0;
	print = (t_print *)malloc(sizeof(t_print));
	print->str = str;
	if (!print)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			i += convert_yes(print, format, ap);
		else
			i += convert_no(print->str, format);
	}
	return (i);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	char	*str;
	va_list	ap;
	int		ret;

	ret = 0;
	str = NULL;
	va_start(ap, format);
	ret = ft_vasprintf(str, format, ap);
	va_end(ap);
	ft_prints(fd, str);
	free(str);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	char	*str;
	va_list	ap;
	int		ret;

	ret = 0;
	str = NULL;
	va_start(ap, format);
	ret = ft_vasprintf(str, format, ap);
	va_end(ap);
	ft_prints(STDOUT_FILENO, str);
	free(str);
	return (ret);
}

int	main(void)
{
	ft_printf("%%\n");
	return(0);
}