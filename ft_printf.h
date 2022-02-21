/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:07:36 by abackman          #+#    #+#             */
/*   Updated: 2022/02/21 17:26:27 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define FLAGS1 "0-+ #"
# define FLAGS2 "cdifFgGsuxXp"

typedef struct s_print
{
	va_list	arg_lst;
	int		arg_num;
	int		arg_cur;
	int		f_width;
	int		bytes;
	char	f_char;
	char	*buf;
}	t_print;
/*
const void	(*f[8])(void *) = {
	ft_getchar(),
	ft_atoi(),
	ft_atoi(),
	ft_float(),

};
*/
#endif
