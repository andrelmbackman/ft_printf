/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:30:27 by abackman          #+#    #+#             */
/*   Updated: 2022/03/09 11:46:26 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static int	conv_print(t_print *print, const char *format)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (format[i])
	{
		printf("conv_print:\n* * * i: %i\n* * * str: %s\n", i, print->str);
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			else if (!ft_strchr(ALL, format[i]))
				i += convert_no(print, &format[i]);
			else
			{
				ret += convert_yes(print, &format[i]);
				i++;
			}
		}
		else
			i += convert_no(print, &format[i]);
	}
	return (i);
}

int	ft_asprintf(char **str, const char *format, ...)
{
	int		ret;
	t_print	*print;

	ret = 0;
	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (-1);
	if (!ft_strlen(format))
		return (0);
	va_start(print->ap, format);
	ret = conv_print(print, format);
	str = &print->str;
	va_end(print->ap);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		ret;
	t_print	*print;

	ret = 0;
	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (-1);
	if (!ft_strlen(format))
		return (0);
	va_start(print->ap, format);
	ret = conv_print(print, format);
	va_end(print->ap);
	ft_prints(fd, print->str);
	free_struct(print);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	t_print	*print;

	ret = 0;
	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (-1);
	if (!ft_strlen(format))
		return (0);
	va_start(print->ap, format);
	conv_print(print, format);
	va_end(print->ap);
	ft_prints(STDOUT_FILENO, print->str);
	ret = ft_strlen(print->str);
	free_struct(print);
	return (ret);
}

int	main(void)
{
	printf("...MAIN...");
	int i = ft_printf("%%hello%c\n%s", 'x', "goodbye");
	printf("...\nreturn of ft_printf: %i\n", i);
	return(0);
}