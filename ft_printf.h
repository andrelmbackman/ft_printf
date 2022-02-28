/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:07:36 by abackman          #+#    #+#             */
/*   Updated: 2022/02/28 15:16:08 by abackman         ###   ########.fr       */
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
# define FLAGS "0-+ #"
# define SPECIFY "%cspdibouxXf"

/*
** Struct in which all useful information is stored
*/

typedef struct s_print
{
	va_list		arg_lst;
	int			arg_num;
	int			arg_cur;
	int			width;
	int			precision;
	int			bytes;
	char		f_char;
	char		*str;
	char		upper;
}	t_print;

/*
** Print functions
*/

int	pr_perc(t_print *print);
int	pr_char(t_print *print);
int	pr_str(t_print *print);
int	pr_ptr(t_print *print);
int	pr_num(t_print *print);
int	pr_bin(t_print *print);
int	pr_oct(t_print *print);
int	pr_u(t_print *print);
int	pr_hex(t_print *print);
int	pr_float(t_print *print);


/*
** Function pointer and dispatch table
*/

typedef int	(*t_able)(t_print *print);

static const t_able dispatch[26] = {
	pr_perc,
	pr_char,
	pr_str,
	pr_ptr,
	pr_num,
	pr_num,
	pr_bin,
	pr_oct,
	pr_u,
	pr_hex,
	pr_hex,
	pr_float,
};

/*
** Other functions
*/

int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		convert_no(char *str, const char *format);
int		convert_yes(t_print *print, const char *format, va_list ap);
char	*strjoin_pro(char *str1, char str2[]);

#endif
