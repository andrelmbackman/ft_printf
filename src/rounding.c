/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:44:44 by abackman          #+#    #+#             */
/*   Updated: 2022/04/20 18:39:34 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/* 
static long double	fmod(long double x, long double y)
{
	unsigned long long	trunc;
	long double			tmp;
	long double			res;
	
	trunc = (unsigned long long) x / y;
	tmp = trunc;
	res = x - tmp * y;
	//printf("\n* * * FMOD * * *\nx: %Lf\ny: %Lf\nmodres: %Lf\n\n", x, y, res);
	return (res);
} */

static int	check_fraction(long double num, int prec, long double pow)
{
	long double			tmp;
	long double			frac;
	unsigned long long	frac_ull;
	unsigned long long	mod;

	tmp = (unsigned long long)num;
	frac = num - tmp;
	frac_ull = (unsigned long long)(frac * pow * 10);
	mod = 1;
	tmp = pow;
	while (pow-- > 0.0)
		tmp *= prec + 1;
	if (frac_ull % (unsigned long long)tmp == 0)
		return (1);
	else
		return (0);
}

static int	check_rounding(long double num, int precision, long double pow)
{
	if ((num * pow) - (unsigned long long)num * pow != 0.5)
		return (0);
	if (check_fraction(num, precision, pow))
		return (1);
	else
		return (0);
}

static long double	do_rounding(long double num, long double pow, int prec)
{
	long double	ret;
	long double	tmp;
	long double	frac;
	
	tmp = num;
	if (prec == 0)
	{
		prec = 1;
		tmp /= 10;
	}
	ret = (unsigned long long)tmp;
	frac = tmp - ret;
	while(prec-- > 0)
		frac *= 10;
	if ((unsigned long long)frac % 2 == 0)
		return (tmp - 0.5 / pow);
	else
		return (tmp + 0.5 / pow);
}

long double	ftoa_rounding(int precision, long double num)
{
	long double			tmp;
	long double			pow;
	unsigned long long	abs;
	
	tmp = num;
	pow = 1.0;
	abs = 0;
	while ((int)abs++ < precision)
		pow *= 10;
	if (check_rounding(tmp, precision, pow))
		tmp = do_rounding(num, pow, precision);
	tmp = tmp + 0.5 / pow;
	return (tmp);
}

/* long double	ftoa_rounding(int precision, long double num)
{
	long double			bank;
	long double			round_check;
	unsigned long long	new_prec;
	unsigned long long	i;

	bank = 0.5;
	round_check = 0.0;
	i = 0;
	if (precision == -1)
		new_prec = 6;
	else
		new_prec = (unsigned long long)precision;
	while (i++ < new_prec)
		bank /= 10.0;
	round_check = 1;
	while ((int)round_check++ < (int)i)
		new_prec *= 10;
	round_check = (long double) (bank + num) * new_prec;
	new_prec = (unsigned long long) round_check;
	i = new_prec;
	while (i % 10 == 0 && i != 0)
		i /= 10;
	//printf("\nROUNDING\nround_check: %Lf\nnew_prec: %llu\nnew_perc / 10: %llu\nwhole number if added rounding: %i\n\n",\
	//	round_check, new_prec, i, precision);
	//if (i > 1 && (new_prec % 2 != 0 || i % 2 != 0))
	//	return (0.0); 
	//if ((fmod(num + bank, bank / 2.5) == bank / 5 && (i % 2 && i > 2)) || fmod(round_check, 1) - 0.5 == 0.0)
	if ((fmod(round_check, 1.0) - 0.5 == 0.0 && (i % 2 && i > 2)) || (precision == 1 && i % 2 && i >= 1))
		return (0.0);
	else
	{
		//printf("\n* * * RETURNING BANK * * *\n\n");
		return (bank);
	}
} */