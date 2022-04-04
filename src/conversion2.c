/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 13:10:23 by abackman          #+#    #+#             */
/*   Updated: 2022/04/04 18:57:53 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	pr_num(t_print *print)
{
	char				*tmp;
	int					i;
	long long			p;

	i = 0;
	p = signed_length_mod(print);
	tmp = ft_itoa_base(p, 10, print);
	//printf("PR_NUM PRECISION: %i\n", print->precision);
	if (print->precision != -1 && (!print->check_neg || !print->p_save))
		tmp = zeropad(tmp, print->precision, p);
	//printf("PR NUM AFTER ZEROPAD: \"%s\"\nprint->zero: %i\nprint->prec: %i\nprint->width: %i\nprint->p_save: %i\n", tmp, print->zero, print->precision, print->width, print->p_save);
	if (print->space && p >= 0 && !print->plus)
		tmp = strjoin_pro(" ", tmp, 2);
	if (print->plus && p >= 0)
		tmp = strjoin_pro("+", tmp, 2);
	tmp = insert_width(print, tmp, 1);
	//printf("* * * TEMPTEMPTEMP * * *\"%s\"\n\n", tmp);
	i = ft_strlen(tmp);
	//printf("\n* * * PR_HEX * * *\nstr: %s\nhash: %i upper: %i", tmp, print->hash, print->upper);
	
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, tmp, 1);
		//print->str = p_strjoin(print->str, str, i);
	else if (print->str == NULL)
		print->str = ft_strdup(tmp);
		//print->str = p_strnew(tmp, i);
		//print->str = tmp;
	ft_strdel(&tmp);
	return (i);
}

int	pr_bin(t_print *print)
{
	char				*tmp;
	int					i;
	unsigned long long	p;

	i = 0;
	p = unsigned_length_mod(print);
	tmp = ft_utoa_base(p, 2, print);
	if (print->precision != -1)
		tmp = zeropad(tmp, print->precision, p);
	tmp = insert_width(print, tmp, 1);
	//printf("* * * TEMPTEMPTEMP * * *\"%s\"\n\n", tmp);
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

int	pr_oct(t_print *print)
{
	char				*tmp;
	int					i;
	unsigned long long	p;	

	i = 0;
	p = unsigned_length_mod(print);
	tmp = ft_utoa_base(p, 8, print);
	if (print->precision != -1)
		tmp = zeropad(tmp, print->precision, p);
	//printf("\n* * * PR_OCT * * *\np: %llu\ntmp: %s\n", p, tmp);
	//if ((print->hash && p) || (print->hash && print->precision != -1))
	if (print->hash && (( p && print->precision == -1) ||\
	(print->precision == 0)))
	{
		tmp = strjoin_pro("0", tmp, 2);
		if (print->upper)
			tmp[1] -= 32;
	}
	//printf("* * * 1TEMPTEMPTEMP * * *\"%s\"\n\n", tmp);
	tmp = insert_width(print, tmp, 1);
	//printf("* * * 2TEMPTEMPTEMP * * *\"%s\"\n\n", tmp);
	i = ft_strlen(tmp);
	//printf("\n* * * PR_OCT * * *\nstr: \"%s\"\nhash: %i upper: %i", tmp, print->hash, print->upper);
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, tmp, 1);
		//print->str = p_strjoin(print->str, str, i);
	else if (print->str == NULL)
		print->str = p_strnew(tmp, i);
		//print->str = tmp;
	ft_strdel(&tmp);
	return (i);
}

int	pr_u(t_print *print)
{
	char				*tmp;
	int					i;
	unsigned long long	p;

	i = 0;
	p = unsigned_length_mod(print);
	tmp = ft_utoa_base(p, 10, print);
	if (print->precision != -1)
		tmp = zeropad(tmp, print->precision, p);
	tmp = insert_width(print, tmp, 1);
	//printf("* * * TEMPTEMPTEMP * * *\"%s\"\n\n", tmp);
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
