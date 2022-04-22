/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apfmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:51:29 by abackman          #+#    #+#             */
/*   Updated: 2022/04/22 16:07:29 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include "./includes//ft_printf.h"

int	main(void)
{
	char	*PF;
	char	*FT;
	int		pf_ret;
	int		ft_ret;
	int		passed;
	int		tests;

	passed = 0;
	tests = 0;
	pf_ret = asprintf(&PF, "Hello World!");
	ft_ret = ft_asprintf(&FT, "Hello World!");
	tests++;
	if (strcmp(PF, FT) != 0)
		printf("error: ft: \"%s\" != pf: \"%s\"\n", FT, PF);
	else if (pf_ret != ft_ret)
		printf("error: ft_asprintf returned %i, asprintf returned %i\n", ft_ret, pf_ret);
	else
		passed++;
	free(PF);
	free(FT);

	pf_ret = asprintf(&PF, "%s", "Vote for Pedro");
	ft_ret = ft_asprintf(&FT, "%s", "Vote for Pedro");
	tests++;
	if (strcmp(PF, FT) != 0)
		printf("error: ft: \"%s\" != pf: \"%s\"\n", FT, PF);
	else if (pf_ret != ft_ret)
		printf("error: ft_asprintf returned %i, asprintf returned %i\n", ft_ret, pf_ret);
	else
		passed++;
	free(PF);
	free(FT);

	pf_ret = asprintf(&PF, "%s", "");
	ft_ret = ft_asprintf(&FT, "%s", "");
	tests++;
	if (strcmp(PF, FT) != 0)
		printf("error: ft: \"%s\" != pf: \"%s\"\n", FT, PF);
	else if (pf_ret != ft_ret)
		printf("error: ft_asprintf returned %i, asprintf returned %i\n", ft_ret, pf_ret);
	else
		passed++;
	free(PF);
	free(FT);

	pf_ret = asprintf(&PF, "%s", NULL);
	ft_ret = ft_asprintf(&FT, "%s", NULL);
	tests++;
	if (strcmp(PF, FT) != 0)
		printf("error: ft: \"%s\" != pf: \"%s\"\n", FT, PF);
	else if (pf_ret != ft_ret)
		printf("error: ft_asprintf returned %i, asprintf returned %i\n", ft_ret, pf_ret);
	else
		passed++;
	free(PF);
	free(FT);

	pf_ret = asprintf(&PF, "%12p", &free);
	ft_ret = ft_asprintf(&FT, "%12p", &free);
	tests++;
	if (strcmp(PF, FT) != 0)
		printf("error: ft: \"%s\" != pf: \"%s\"\n", FT, PF);
	else if (pf_ret != ft_ret)
		printf("error: ft_asprintf returned %i, asprintf returned %i\n", ft_ret, pf_ret);
	else
		passed++;
	free(PF);
	free(FT);
	
	pf_ret = asprintf(&PF, "%.20f", -0.0);
	ft_ret = ft_asprintf(&FT, "%.20f", -0.0);
	tests++;
	if (strcmp(PF, FT) != 0)
		printf("error: ft: \"%s\" != pf: \"%s\"\n", FT, PF);
	else if (pf_ret != ft_ret)
		printf("error: ft_asprintf returned %i, asprintf returned %i\n", ft_ret, pf_ret);
	else
		passed++;
	free(PF);
	free(FT);

	pf_ret = asprintf(&PF, "X%-20c", 0);
	ft_ret = ft_asprintf(&FT, "X%-20c", 0);
	tests++;
	if (strcmp(PF, FT) != 0)
		printf("error: ft: \"%s\" != pf: \"%s\"\n", FT, PF);
	else if (pf_ret != ft_ret)
		printf("error, c with 0: ft_asprintf returned %i, asprintf returned %i\n", ft_ret, pf_ret);
	else
		passed++;
	free(PF);
	free(FT);
	
	
	if (passed == tests)
		printf("Great success!\n");
	//system("leaks a.out");
	return (0);
}
