/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:30:30 by abackman          #+#    #+#             */
/*   Updated: 2022/04/05 20:38:38 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long double	ftoa_rounding(t_print *p, long double num)
{
	long double	bank;
	long double	tmp;
	int			p;

	bank = 0.5;
	tmp = 10.0;
	p = 0;
	if (num < 0)
		bank *= -1;
	while (p < p->precision)
	{
		bank /= tmp;
		p++;
	}
	tmp = num + bank;
	return (tmp);
}

static char	*after_decimal(t_print *p, long double num, long double prec)
{

}

static char	*ftoa(t_print *p, long double num)
{
	char				*nbr;
	char				*dot;
	long long			n;
	long double			prec;
	int					i;

	i = 0;
	num = ftoa_rounding(p, num);
	n = (long long)num;
	nbr = ft_itoa_base(n, 10, p);
	if (p->precision == -1)
		prec = 6;
	else
		prec = p->precision;
	dot = (char *)malloc(prec + 2 * sizeof(char));
	if (!dot)
		return (nbr);
	if (prec > 0)
		dot[i++] = '.';
	else
		dot[i] = '\0';
	
	
	
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
