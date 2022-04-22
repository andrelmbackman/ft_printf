/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dpfmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:54:03 by abackman          #+#    #+#             */
/*   Updated: 2022/04/22 14:34:53 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <fcntl.h>
#include "./includes/ft_printf.h"

int	main(int argc, char **argv)
{
	int	fd1;
	int	fd2;

	if (argc != 3)
	{
		ft_printf("usage: ./a.out printf_file_name ft_printf_file_name\n");
		return (1);
	}
	fd1 = open(argv[1], O_RDWR);
	fd2 = open(argv[2], O_RDWR);
	if (fd1 < 0 || fd2 < 0)
	{
		ft_printf("error opening file(s)\n");
		return (1);
	}
	dprintf(fd1, "Hello World!\n");
	ft_dprintf(fd2, "Hello World!\n");

	dprintf(fd1, "\n%s\n", "testing string conversion");
	ft_dprintf(fd2, "\n%s\n", "testing string conversion");
	dprintf(fd1, "\"Hello World\" with .5 precision: %.5s\n", "Hello World");
	ft_dprintf(fd2, "\"Hello World\" with .5 precision: %.5s\n", "Hello World");

	dprintf(fd1, "\ntesting char conversion: %c\n", 'Q');
	ft_dprintf(fd2, "\ntesting char conversion: %c\n", 'Q');

	dprintf(fd1, "\nint min: %i\n", INT32_MIN);
	ft_dprintf(fd2, "int min: %i\n", INT32_MIN);
	dprintf(fd1, "\nint max: %i\n", INT32_MAX);
	ft_dprintf(fd2, "\nint max: %i\n", INT32_MAX);

	dprintf(fd1, "\npointer: %p\n", &free);
	ft_dprintf(fd2, "\npointer: %p\n", &free);

	dprintf(fd1, "\n42 in octal: %o\n", 42);
	ft_dprintf(fd2, "\n42 in octal: %o\n", 42);
	dprintf(fd1, "42 with # and .5 in octal: %#.5o\n", 42);
	ft_dprintf(fd2, "42 with # and .5 in octal: %#.5o\n", 42);
	dprintf(fd1, "0 with # in octal: %#o\n", 0);
	ft_dprintf(fd2, "0 with # in octal: %#o\n", 0);

	dprintf(fd1, "\n42 in hex: %x\n", 42);
	ft_dprintf(fd2, "\n42 in hex: %x\n", 42);
	dprintf(fd1, "42 with # and .5 in HEX: %#.5X\n", 42);
	ft_dprintf(fd2, "42 with # and .5 in HEX: %#.5X\n", 42);
	dprintf(fd1, "0 with # in HEX: %#X\n", 0);
	ft_dprintf(fd2, "0 with # in HEX: %#X\n", 0);

	dprintf(fd1, "ULLONG_MAX: %llu\n", ULLONG_MAX);
	ft_dprintf(fd2, "ULLONG_MAX: %llu\n", ULLONG_MAX);

	dprintf(fd1, "\nfloat -0.0: %f\n", -0.0);
	ft_dprintf(fd2, "\nfloat -0.0: %f\n", -0.0);
	dprintf(fd1, "float 0.25 with 1 precision: %.1f\n", 0.25);
	ft_dprintf(fd2, "float 0.25 with 1 precision: %.1f\n", 0.25);
	return (0);
}
