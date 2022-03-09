/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:59:31 by abackman          #+#    #+#             */
/*   Updated: 2022/03/09 14:49:11 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	pr_perc(t_print *print)
{
	char	*perc;

	perc = (char *)malloc(2 * sizeof(char));
	if (!perc)
		return (-1);
	perc[0] = '%';
	perc[1] = '\0';
	if (print->str == NULL)
		print->str = perc;
	else
		print->str = strjoin_pro(print->str, perc);
	if (print->str)
		return (1);
	else
		return (-1);
}

int	pr_char(t_print *print)
{
	char	*str;
	char	c;

	c = (char)va_arg(print->ap, int);
	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (-1);
	str[0] = c;
	str[1] = '\0';
	if (print->str == NULL)
		print->str = str;
	else
		print->str = strjoin_pro(print->str, str);
	if (print->str)
		return (1);
	else
		return (-1);
}

int	pr_str(t_print *print)
{
	char	*str;
	int		i;

	str = va_arg(print->ap, char *);
	i = ft_strlen(str) - print->precision;
	if (str == NULL)
	{
		str = strnull();
		i = 6;
	}
	//printf("PR_STR: i: %i\nstr: %s", i, print->str);
	if (print->str)
		print->str = p_strjoin(print->str, str, i);
	else
		print->str = p_strnew(str, i);
	//printf("\nNEW: \"%s\"\n", print->str);
	return (i);
}

int	pr_ptr(t_print *print)
{
	return (0);
}
int	pr_num(t_print *print)
{
	return (0);
}
int	pr_bin(t_print *print)
{
	return (0);
}
int	pr_oct(t_print *print)
{
	return (0);
}
int	pr_u(t_print *print)
{
	return (0);
}
int	pr_hex(t_print *print)
{
	return (0);
}
int	pr_float(t_print *print)
{
	return (0);
}