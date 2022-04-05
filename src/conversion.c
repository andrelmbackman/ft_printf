/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:59:31 by abackman          #+#    #+#             */
/*   Updated: 2022/04/05 17:30:06 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	pr_perc(t_print *print)
{
	char	*perc;

	perc = (char *)malloc(2 * sizeof(char));
	if (!perc)
		return (-1);
	perc[0] = '%';
	perc[1] = '\0';
	if (print->width)
		perc = insert_width(print, perc, 1);
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, perc, 3);
	else
		print->str = perc;
	if (print->width)
		return (print->width);
	else
		return (1);
}

int	pr_char(t_print *print)
{
	char			*str;
	unsigned char	c;
	if (print->str != NULL)
		ft_strdel(&print->str);

	c = (unsigned char)va_arg(print->ap, int);
	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (-1);
	str[0] = c;
	str[1] = '\0';
	if (print->width)
	{
		if (!ft_isprint(c))
			str = insert_space_only(print, str);
		else 
			str = insert_width(print, str, 1);
	}
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, str, 1);
	else if (print->str == NULL)
		print->str = str;
	//printf("* * * CHAR * * *\nstr: \"%s\"\np->str: \"%s\"\n", str, print->str);
	//ft_strdel(&str);
	/* write(1, "{", 1);
	write(1, str, 5);
	write(1, "}", 1); */
	if (print->width)
		return (print->width);
	else
		return (1);
}

int	pr_str(t_print *print)
{
	char	*tmp;
	char	*new;
	int		i;

	i = 0;
	tmp = va_arg(print->ap, char *);
	if (tmp == NULL || !ft_strcmp(tmp, "") || (print->precision == 0 &&\
	!print->check_neg))
		new = strnull(print, tmp);
	else
		new = ft_strdup(tmp);
	//printf("PR_STR: \"%s\"\np->precision: %i\np->check_neg: %i", new, print->precision, print->check_neg);
	if (print->precision > 0 && !print->check_neg)
	{
		while (new[print->precision] != '\0')
		{
			new[print->precision] = '\0';
			print->precision++;
		}
	}
	//printf("\nPR_STR1: i: %i\nstr: \"%s\"", i, new);
	new = insert_width(print, new, 1);
	//printf("\nPR_STR2: NEW: \"%s\" P->STR: \"%s\"\n", new, print->str);
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, new, 1);
	else
		print->str = ft_strdup(new);
		//print->str = new;
	ft_strdel(&new);
	//printf("\nPR_STR3: i: %i\nstr: \"%s\"\nPR_STR3 p->str[i]: %c", i, print->str, print->conv);
	return (ft_strlen(print->str));
}

int	pr_ptr(t_print *print)
{
	char			*tmp;
	int				i;
	unsigned long	p;

	i = 0;
	p = 0;
	p = va_arg(print->ap, unsigned long);
	tmp = ft_utoa_base(p, 16, print);
	i = ft_strlen(tmp);
	tmp = strjoin_pro("0x", tmp, 2);
	tmp = insert_width(print, tmp, 1);
	i = ft_strlen(tmp);
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, tmp, 1);
		//print->str = p_strjoin(print->str, str, i);
	else
		print->str = p_strnew(tmp, i);
		//print->str = tmp;
	ft_strdel(&tmp);
	return (i);
}

int	pr_hex(t_print *print)
{
	char				*tmp;
	int					i;
	unsigned long long	p;

	i = 0;
	p = unsigned_length_mod(print);
	tmp = ft_utoa_base(p, 16, print);
	if (print->precision != -1)
		tmp = zeropad(tmp, print->precision, p);
	//printf("\n* * * HEX1 * * *\ntmp: \"%s\"\nhash: %i\np: %lld\nprecision: %i\nminus: %i\n", tmp, print->hash, p, print->precision, print->minus);
	if (print->hash && p)
	{
		tmp = strjoin_pro("0x", tmp, 2);
		if (print->upper)
			tmp[1] -= 32;
	}
	//printf("* * * HEXHEXHEX * * *\n\"%s\"\n\n", tmp);
	tmp = insert_width(print, tmp, 1);
	i = ft_strlen(tmp);
	//printf("\n* * * PR_HEX * * *\nstr: %s\nhash: %i upper: %i", tmp, print->hash, print->upper);
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, tmp, 1);
		//print->str = p_strjoin(print->str, str, i);
	else if (print->str == NULL)
		print->str = p_strnew(tmp, i);
		//print->str = tmp;
	ft_strdel(&tmp);
	return (i);
}
