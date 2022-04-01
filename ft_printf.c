/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:30:27 by abackman          #+#    #+#             */
/*   Updated: 2022/04/01 19:23:08 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	conv_asprint(t_print *p, const char *format)
{
	p->i = 0;
	p->ret = 0;
	while (format[p->i])
	{
		//printf("conv_print:\n* * * i: %i\n* * * str: %s\n", p->i, p->str);
		if (format[p->i] == '%')
		{
			p->i++;
			if (format[p->i] == '\0')
				break ;
			else if (ft_strchr(ALL, format[p->i]))
			{
				p->i += as_convert_yes(p, format);
			}
			else
				p->i += as_convert_no(p, &format[p->i]);
		}
		else
			p->i += as_convert_no(p, &format[p->i]);
	}
	return (p->i);
}

static int	conv_print(t_print *p, const char *format)
{
	p->i = 0;
	p->ret = 0;
	while (format[p->i])
	{
		//printf("conv_print:\n* * * i: %i\n* * * str: %s\n", p->i, p->str);
		if (format[p->i] == '%')
		{
			p->i++;
			if (format[p->i] == '\0')
				break ;
			else if (ft_strchr(ALL, format[p->i]))
			{
				convert_yes(p, format);
				p->i++;
			}
			else
				p->i += convert_no(p, &format[p->i]);
		}
		else
			p->i += convert_no(p, &format[p->i]);
	}
	return (p->ret);
}

int	ft_asprintf(char **str, const char *format, ...)
{
	int		ret;
	t_print	*print;

	ret = 0;
	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (-1);
	print->fd = 0;
	if (!ft_strlen(format))
		return (0);
	va_start(print->ap, format);
	conv_asprint(print, format);
	va_end(print->ap);
	*str = ft_strdup(print->str);
	free_struct(print);
	return (ft_strlen(*str));
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		ret;
	t_print	*print;

	ret = 0;
	print = (t_print *)malloc(sizeof(t_print));
	if (!print)
		return (-1);
	print->fd = fd;
	if (!ft_strlen(format))
		return (0);
	va_start(print->ap, format);
	conv_print(print, format);
	va_end(print->ap);
	ret = ft_strlen(print->str);
	write(fd, print->str, (size_t)ret);
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
	print->fd = STDOUT_FILENO;
	if (!ft_strlen(format))
		return (0);
	va_start(print->ap, format);
	conv_print(print, format);
	va_end(print->ap);
	ret = print->ret;
	free_struct(print);
	return (ret);
}

/*
int	main(void)
{
	printf("...MAIN...");
	int i = ft_printf("\n%%hello%c\n%.4sX", 'x', "goodbye");
	printf("\n...return of ft_printf: %i\n", i);


	char	c1 = 'x';
	char	*cp1 = &c1;
	
	printf("\nprintf    pointer: %p\n", cp1);
	ft_printf("ft_printf pointer: %p\n", cp1);
	printf("printf    NULL pointer: %p\n", NULL);
	ft_printf("ft_printf NULL pointer: %p\n", NULL);


	printf("\nprintf    hex: %*-6x\n", 10, c1 + c1);
	ft_printf("ft_printf hex: %*-6x\n", 10, c1 + c1);
	printf("printf    HEX: %#010.9X\n", c1 + c1 + 1);
	ft_printf("ft_printf HEX: %#010.9X\n", c1 + c1 + 1);
	

	printf("\nprintf    str: %0-10sX\n", "hello");
	ft_printf("ft_printf str: %0-10sX\n", "hello");
	printf("\nprintf    str: %010sX\n", "world");
	ft_printf("ft_printf str: %010sX\n", "world");

	printf("\nprintf    NUL: %-10sX\n", NULL);
	ft_printf("ft_printf NUL: %-10sX\n", NULL);
	printf("printf    NUL: %10.4s\n", NULL);
	ft_printf("ft_printf NUL: %10.4s\n", NULL);
	printf("printf    NUL: %s\n", NULL);
	ft_printf("ft_printf NUL: %s\n", NULL);


	long long	j = 99999999999;
	long long	i = (short)j;
	printf("\n%lli\n", i);
	ft_printf("FT O:%#o\n", 0);
    printf("PF O:%#o\n\n", 0);

    ft_printf("FT D:{% 03d}\n", 0);
    printf("PF D:{% 03d}\n\n", 0);

    ft_printf("FT X:%.4x\n", 42);
    printf("PF X:%.4x\n\n", 42);

    ft_printf("FT X:{%#.5x}\n", 1);
    printf("PF X:{%#.5x}\n\n", 1);

    ft_printf("FT S:{%.*s}\n", -5, "42");
    printf("PF S:{%.*s}\n\n", -5, "42"); 
	return(0);
}
*/