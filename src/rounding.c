/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:44:44 by abackman          #+#    #+#             */
/*   Updated: 2022/04/21 19:19:27 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/* static long double	fmod(long double x, long double y)
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

/* static int	check_fraction(long double num, int prec, long double pow)
{
	int					new_prec;
	long double			tmp;
	long double			frac;
	unsigned long long	frac_ull;
	unsigned long long	mod;

	//printf("* * * 3CHECK_FRACTION * * *\n");
	tmp = (unsigned long long)num;
	frac = num - tmp;
	frac_ull = (unsigned long long)(frac * pow * 10);
	mod = 1;
	new_prec = prec + 1;
	while (new_prec-- > 0)
		mod *=  5;
	//rintf("frac: %Lf\nfrac_ull: %llu\npow: %Lf\nmod: %llu\n", frac, frac_ull, pow, mod);
	if (frac_ull % mod == 0)
		return (1);
	else
		return (0);
}

static int	check_rounding(long double num, int precision)
{
	long double	div;
	int			tmp;
	long double	trunc;
	
	div = 1.0;
	tmp = precision;
	while (tmp-- > 0)
		div *= 10;
	trunc = num * div;
	trunc = (unsigned long long)trunc;
	//check = (num * div) - (unsigned long long) num * div;
	//printf("\n* * * 2CHECK_ROUNDING * * *\nnum: %Lf\nprec: %i\ndiv: %Lf\n num * div - (int)num * div: %Lf\n", num, precision, div, trunc);
	if (num * div - trunc != 0.5)
		return (0);
	if (check_fraction(num, precision, div))
		return (1);
	else
		return (0);
}

static long double	do_rounding(long double num, long double pow, int prec)
{
	//long double	ret;
	long double	tmp;
	long double	frac;
	int			new_prec;
	
	tmp = num;
	new_prec = prec;
	if (new_prec == 0)
	{
		new_prec = 1;
		tmp /= 10;
	}
	//printf("\n* * * 4DO ROUNDING * * *\n");
	tmp = (unsigned long long)tmp;
	frac = num - tmp;
	while(new_prec-- > 0)
		frac *= 10;
	//frac += 0.5;
	//printf("int part: %Lf\nfrac part: %Lf\nnum: %Lf\nprec: %i\npow: %Lf\n", tmp, frac, num, prec, pow);
	//printf("ULL CAST FRAC: %llu\n", (unsigned long long)frac);
	if ((unsigned long long)frac % 2 == 0)
		return (num - 0.5 / pow);
	else
		return (num + 0.5 / pow);
}

long double	ftoa_rounding(int precision, long double num)
{
	long double			tmp;
	long double			pow;
	int					i;
	
	//printf("\n* * * 1FTOA_ROUNDING * * *\n");
	tmp = num;
	pow = 1.0;
	i = 0;
	while (i++ < precision)
		pow *= 10;
	//printf("prec: %i\npower: %Lf\n\n", precision, pow);
	if (check_rounding(tmp, precision))
		tmp = do_rounding(num, pow, precision);
	//printf("* * * 5AFTER ROUND * * *\n %Lf\n", tmp);
	tmp += (0.5 / pow);
	return (tmp);
} */

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
	round_check = 0;
	new_prec = 1;
	while ((int)round_check++ < (int)i)
		new_prec *= 10;
	round_check = (long double) (bank + num) * new_prec;
	i = (unsigned long long) round_check;
	while (i % 10 == 0 && i != 0)
		i /= 10;
	//printf("\nROUNDING\nround_check: %Lf\nnew_prec: %llu\n", round_check, new_prec);
	//printf("new_perc / 10: %llu\nwhole number if added rounding: %i\n\n", i, precision);
	//if (i > 1 && (new_prec % 2 != 0 || i % 2 != 0))
	//	return (0.0); 
	//if ((fmod(num + bank, bank / 2.5) == bank / 5 && (i % 2 && i > 2)) || fmod(round_check, 1) - 0.5 == 0.0)
	//if ((fmod(round_check, 1.0) - 0.5 == 0.0 && i % 2 && fmod(num, bank / 2.5) == 0.0) || (precision == 1 && i % 2))
	if (fmod(round_check, 2.0) != 0.0 && ( i % 2 && i > 1))
		return (num);
	else
	{
		//printf("\n* * * RETURNING BANK * * *\n\n");
		return (num + bank);
	}
} */

/* static long double add_bank(long double num, int pow)
{
	
} */

long double	ftoa_rounding(int prec, long double num)
{
	long double			pow;
	long double			tmp;
	int					i;
	int					nprec;

	i = 0;
	pow = 1.0;

	if (prec == -1)
		nprec = 6;
	else
		nprec = prec;
	if (prec == 0)
	{
		nprec = 1;
		pow /= 10;
	}
	while (i++ < nprec)
		pow *= 10;
	tmp = num;
	tmp *= pow;
	//tmp += 0.5;
	//printf("\nFTOA ROUNDING\ntmp: %Lf\npow: %Lf\nprec: %i\n\n", tmp, pow, prec);
	if ((unsigned long long)tmp % 2 == 0 && tmp - (unsigned long long)tmp == 0.5)
		return (num);
	else
		return (num + 0.5 / pow);
}