/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:55:36 by abackman          #+#    #+#             */
/*   Updated: 2022/03/30 14:56:29 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "./includes/ft_printf.h"
# define RESET "\033[0m"
# define RED "\033[0;31m"

static float	divise(float a, float b)
{
	return (a / b);
}

int	main(void)
{
	//printf("float: %+.5f\n", divise(1.1, 3.1));

	int	passed;
	int	pf = 0;
	int	ft = 0;

	passed = 0;
/*
	printf("%#x", 42);
	printf("\n");
	ft_printf("%#x", 42);
	printf("\n");
	printf("%#llx", 9223372036854775807);
	printf("\n");
	ft_printf("%#llx", 9223372036854775807);
	printf("\n");
	printf("%#8x", 42);
	printf("\n");
	ft_printf("%#8x", 42);
	printf("\n");
	printf("%#08x", 42);
	printf("\n");
	ft_printf("%#08x", 42);
	printf("\n");
	printf("%#-08x", 42);
	printf("\n");
	ft_printf("%#-08x", 42);
	printf("@moulitest: %#.x %#.0xX", 0, 0);
	printf("\n");
	ft_printf("@moulitest: %#.x %#.0xX", 0, 0);
	printf("\n");
	
	printf("%.2s is a string", "this");
	printf("\n");
	printf("%.2s is a string", "this");
	printf("\n");
	printf("%2c", 0);
	printf("\n");
	ft_printf("%2c", 0);
	printf("\n");
	printf("%.2c", NULL);
	printf("\n");
	ft_printf("%.2c", NULL);
	printf("\n");
	*/

	/*
	printf("%c", 42);
	printf("\n");
	ft_printf("%c", 42);
	printf("\n");
	printf("@moulitest: %cX", 0);
	printf("\n");
	ft_printf("@moulitest: %cX", 0);
	printf("\n");
	printf("%2cX", 0);
	printf("\n");
	ft_printf("%2cX", 0);
	printf("\n");
	
	printf("%%");
	printf("\n");
	ft_printf("%%");
	printf("\n");
	printf("% 10.5d", 4242);
	printf("\n");
	ft_printf("% 10.5d", 4242);
	printf("\n");
	printf("%03.2d", 0);
	printf("\n");
	ft_printf("%03.2d", 0);
	printf("\n");
	ft_printf("%03.2d", -1);
	printf("\n");
	printf("%03.2d", -1);
	printf("\n");
	ft_printf("%03.2d", -1);
	printf("\n");
	printf("%08.5u", 34);
	printf("\n");
	ft_printf("%08.5u", 34);
	pf = printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	printf("\n");
	ft = ft_printf("%s%s%s%s%s", "1", "2", "3", "4", "5");
	printf("\nPF return: %i\nFT return: %i\n\n", pf, ft);
	
	pf = printf("%");
	printf("\n");
	ft = ft_printf("%");
	printf("\nPF return: %i\nFT return: %i\n\n", pf, ft);
	
	pf = printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	printf("\n");
	ft = ft_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");
	printf("\nPF return: %i\nFT return: %i\n\n", pf, ft);
	
	pf = printf("a%ob%oc%od", 0, 55555, 100000);
	printf("\n");
	ft = ft_printf("a%ob%oc%od", 0, 55555, 100000);
	printf("\nPF return: %i\nFT return: %i\n\n", pf, ft);

	pf = printf("{%05.*d}", -15, 42);
	printf("\n");
	ft = ft_printf("{%05.*d}", -15, 42);
	printf("\nPF return: %i\nFT return: %i\n", pf, ft);
	*/
	ft_printf("FT *S:{%.*s}\n", 0, "hello");
    printf("PF *S:{%.*s}\n\n", 0, "hello");

    ft_printf("FT S:{%.0s}\n", "hello");
    printf("PF S:{%.0s}\n\n", "hello");

    ft_printf("FT *S:{%.*s}\n", -5, "42");
    printf("PF *S:{%.*s}\n\n", -5, "42");

    ft_printf("FT S:{%-5.s}\n","42");
    printf("PF S:{%-5.s}\n\n","42"); 
	/*
	printf("%c", 0);
	printf("\n");
	ft_printf("%c", 0);
	*/
	//system("leaks a.out");
	return (0);
}
