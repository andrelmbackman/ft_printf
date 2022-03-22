/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:59:31 by abackman          #+#    #+#             */
/*   Updated: 2022/03/22 19:25:17 by abackman         ###   ########.fr       */
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
		print->str = strjoin_pro(print->str, perc, 3);
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
	//printf("\nPrint char: %c\n", c);
	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (-1);
	str[0] = c;
	str[1] = '\0';
	if (print->str == NULL)
		print->str = str;
	else
		print->str = strjoin_pro(print->str, str, 3);
	if (print->str)
		return (1);
	else
		return (-1);
}

int	pr_str(t_print *print)
{
	char	*tmp;
	int		i;

	tmp = va_arg(print->ap, char *);
	if (tmp == NULL || !ft_strcmp(tmp, "") || print->precision == 0)
		tmp = strnull(print, tmp, i);
	//printf("PR_STR: %s\n", str);
	if (print->precision > 0)
		i = print->precision;
	else if (print->precision == -1)
		i = ft_strlen(tmp);
	//printf("PR_STR: i: %i\nstr: %s", i, print->str);
	if (print->str)
	{
		print->str = p_strjoin(print->str, tmp, i);
	}
	else
		print->str = p_strnew(tmp, i);
	//print->str = insert_width(print);
	return (i);
}

int	pr_ptr(t_print *print)
{
	char			*tmp;
	int				i;
	unsigned long	p;

	p = va_arg(print->ap, unsigned long);
	tmp = ultoa_base(p, 16, print);
	tmp = strjoin_pro("0x", tmp, 2);
	i = ft_strlen(tmp);
	if (print->str)
		print->str = strjoin_pro(print->str, tmp, 3);
		//print->str = p_strjoin(print->str, str, i);
	else
		print->str = tmp;
		//print->str = p_strnew(str, i);
	return (i);
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
	char			*tmp;
	int				i;
	unsigned long	p;

	p = va_arg(print->ap, unsigned long);
	tmp = ultoa_base(p, 16, print);
	if (print->precision != -1)
		tmp = zeropad(tmp, print->precision);
	if (print->hash)
	{
		tmp = strjoin_pro("0x", tmp, 2);
		if (print->upper)
			tmp[1] -= 32;
	}
	tmp = insert_width(print, tmp);
	//printf("* * * TEMPTEMPTEMP * * *\"%s\"\n\n", tmp);
	i = ft_strlen(tmp);
	//printf("\n* * * PR_HEX * * *\nstr: %s\nhash: %i upper: %i", tmp, print->hash, print->upper);
	if (print->str)
		print->str = strjoin_pro(print->str, tmp, 3);
		//print->str = p_strjoin(print->str, str, i);
	else
		print->str = tmp;
		//print->str = p_strnew(str, i);
	return (i);
}
int	pr_float(t_print *print)
{
	return (0);
}