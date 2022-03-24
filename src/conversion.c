/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:59:31 by abackman          #+#    #+#             */
/*   Updated: 2022/03/24 16:46:20 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	pr_perc(t_print *print)
{
	char	*perc;

	printf("\nPR_PERC: width: %i", print->width);
	perc = (char *)malloc(2 * sizeof(char));
	if (!perc)
		return (-1);
	perc[0] = '%';
	perc[1] = '\0';
	perc = insert_width(print, perc, 1);
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
	str = insert_width(print, str, 1);
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
	char	*new;
	int		i;

	i = 0;
	tmp = va_arg(print->ap, char *);
	//printf("PR_STR: %s\n", tmp);
	if (tmp == NULL || !ft_strcmp(tmp, "") || print->precision == 0)
		new = strnull(print, tmp);
	if (print->precision > 0)
		i = print->precision;
	else if (print->precision == -1)
	{
		if (tmp)
			i = ft_strlen(tmp);
		else
			i = ft_strlen(new);
	}
	//printf("\nPR_STR1: i: %i\nstr: \"%s\"", i, print->str);
	if (tmp)
		new = insert_width(print, tmp, 0);
	else
		new = insert_width(print, new, 1);
	//printf("\nPR_STR2: NEW: \"%s\" P->STR: \"%s\"\n", new, print->str);
	if (print->str)
		print->str = strjoin_pro(print->str, new, 1);
	else
		print->str = ft_strdup(new);
	ft_strdel(&new);
	//printf("\nPR_STR3: i: %i\nstr: \"%s\"\nPR_STR3 p->str[i]: %c", i, print->str, print->conv);
	return (i);
}

int	pr_ptr(t_print *print)
{
	char			*tmp;
	int				i;
	unsigned long	p;

	i = 0;
	p = va_arg(print->ap, unsigned long);
	tmp = ft_ultoa_base(p, 16, print);
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

int	pr_hex(t_print *print)
{
	char				*tmp;
	int					i;
	unsigned long long	p;

	i = 0;
	p = unsigned_length_mod(print);
	tmp = ft_ultoa_base(p, 16, print);
	if (print->precision != -1)
		tmp = zeropad(tmp, print->precision);
	if (print->hash)
	{
		tmp = strjoin_pro("0x", tmp, 2);
		if (print->upper)
			tmp[1] -= 32;
	}
	tmp = insert_width(print, tmp, 1);
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
	if (print)
		return (1);
	return (0);
}
