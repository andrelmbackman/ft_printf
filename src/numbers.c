/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:15:34 by abackman          #+#    #+#             */
/*   Updated: 2022/04/07 19:40:33 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

double	init_dot(long double num, long long whole, int prec)
{
	double		power10[10];
	double		dot;

	power10[0] = 1;
	power10[1] = 10;
	power10[2] = 100;
	power10[3] = 1000;
	power10[4] = 10000;
	power10[5] = 100000;
	power10[6] = 1000000;
	power10[7] = 10000000;
	power10[8] = 100000000;
	power10[9] = 1000000000;
	dot = (num - whole) * power10[prec];
	return (dot);
}