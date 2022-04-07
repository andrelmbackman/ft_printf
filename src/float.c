/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:30:30 by abackman          #+#    #+#             */
/*   Updated: 2022/04/06 16:54:34 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long double	ftoa_rounding(t_print *p, long double num)
{
	long double	bank;
	long double	tmp;
	int			i;

	bank = 0.5;
	tmp = 10.0;
	i = 0;
	if (num < 0)
		bank *= -1;
	while (i < p->precision)
	{
		bank /= tmp;
		i++;
	}
	tmp = num + bank;
	return (tmp);
}

static char	*after_decimal(t_print *p, long double num, long long whole)
{
	char				*buf;
	long long			tmp;
	double				dot;
	int					prec;
	int					len;
	int					i;
	static const double	power10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000,\
	10000000, 100000000, 1000000000 };

	i = 0;
	if (p->precision == -1)
		prec = 6;
	else
		prec = p->precision;
	dot = (num - whole) * power10[prec];
	tmp = (long long)dot;
	len = ll_len(tmp);
	//printf("* * FLOAT * *\nlen: %i\nprec: %i\ndot: %f\ntmp: %lli\n\n", len, prec, dot, tmp);
	buf = (char *)malloc(prec + 2 * sizeof(char));
	while (tmp > 0)
	{
		buf[i] = tmp % 10 + '0';
		tmp /= 10;
		i++;
	}
	while (len < prec)
	{
		buf[i] = '0';
		i++;
		len++;
	}
	if (prec > 0)
	{
		buf[i++] = '.';
		buf[i] = '\0';
	}
	else
		buf[0] = '\0';
	str_reverse(buf);
	//buf = ft_itoa_base(tmp, 10, p);
	return (buf);
}

static char	*ftoa(t_print *p, long double num)
{
	char				*nbr;
	char				*dot;
	char				*ret;
	long long			whole;

	num = ftoa_rounding(p, num);
	whole = (long long)num;
	nbr = ft_itoa_base(whole, 10, p);
	dot = after_decimal(p, num, whole);
	ret = strjoin_pro(nbr, dot, 2);
	return (ret);
}

int	pr_float(t_print *p)
{
	char		*new;
	long double	num;
	int			len;
	
	if (p->L)
		num = (long double)va_arg(p->ap, long double);
	else
		num = (double)va_arg(p->ap, double);
	new = ftoa(p, num);
	new = insert_width(p, new, 1);
	len = ft_strlen((const char *)new);
	if (p->str != NULL)
		p->str = strjoin_pro(p->str, new, 1);
	else if (p->str == NULL)
		p->str = p_strnew((const char *)new, len);
	ft_strdel(&new);
	return (len);
}
