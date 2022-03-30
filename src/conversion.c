/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:59:31 by abackman          #+#    #+#             */
/*   Updated: 2022/03/30 12:12:34 by abackman         ###   ########.fr       */
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
	if (!print->str)
		print->str = perc;
	else
		print->str = strjoin_pro(print->str, perc, 3);
	if (print->width)
		return (print->width);
	else
		return (1);
}

int	pr_char(t_print *print)
{
	char			*str;
	unsigned char	c;

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
	if (print->str)
		print->str = strjoin_pro(print->str, str, 2);
	else
		print->str = str;
	//printf("* * * CHAR * * *\nstr: \"%s\"\np->str: \"%s\"\n", str, print->str);
	//ft_strdel(&str);
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
	//printf("PR_STR: %s\n", tmp);
	if (tmp == NULL || !ft_strcmp(tmp, "") || print->precision == 0)
		new = strnull(print, tmp);
	else
		new = ft_strdup(tmp);
	if (print->precision != -1)
	{
		while (new[print->precision] != '\0')
		{
			new[print->precision] = '\0';
			print->precision++;
		}
	}
	//printf("\nPR_STR1: i: %i\nstr: \"%s\"", i, print->str);
	new = insert_width(print, new, 1);
	//printf("\nPR_STR2: NEW: \"%s\" P->STR: \"%s\"\n", new, print->str);
	if (print->str)
		print->str = strjoin_pro(print->str, new, 1);
	else
		print->str = ft_strdup(new);
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
	p = va_arg(print->ap, unsigned long);
	tmp = ft_utoa_base(p, 16, print);
	tmp = strjoin_pro("0x", tmp, 2);
	tmp = insert_width(print, tmp, 1);
	i = ft_strlen(tmp);
	if (print->str)
		print->str = strjoin_pro(print->str, tmp, 3);
		//print->str = p_strjoin(print->str, str, i);
	else
		print->str = tmp;
		//print->str = p_strnew(str, i);
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
	//printf("\n* * * HEX1 * * *\nhash: %i\np: %lld\nprecision: %i\nminus: %i\n", print->hash, p, print->precision, print->minus);
	if (print->hash != 0 && p != 0)
	{
		tmp = strjoin_pro("0x", tmp, 2);
		if (print->upper)
			tmp[1] -= 32;
	}
	//printf("* * * HEXHEXHEX * * *\n\"%s\"\n\n", tmp);
	tmp = insert_width(print, tmp, 1);
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
	if (print)
		return (1);
	return (0);
}
