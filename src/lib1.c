/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:00:34 by abackman          #+#    #+#             */
/*   Updated: 2022/04/25 12:33:03 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_strdel(char **as)
{
	if (as == NULL)
		return ;
	free(*as);
	*as = NULL;
}

int	ft_strcmp(const char *s1, const char *s2)
{	
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	c1 = (unsigned char)s1[i];
	c2 = (unsigned char)s2[i];
	return (c1 - c2);
}
