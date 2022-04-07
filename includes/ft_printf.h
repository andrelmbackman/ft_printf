/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:07:36 by abackman          #+#    #+#             */
/*   Updated: 2022/04/06 15:04:12 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>
/*
 *iyy DELETE Îî DELETEDELETEDELETEppppppppppppppppppppppppppp
 *iyy DELETE Îî DELETEDELETEDELETE
 */

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define FLAGS "0-+ #.*0123456789hlL"
# define SPECIFY "%cspdibouxXf"
# define ALL "0-+ #.*0123456789hlL%cspdibouxXf"

/*
** Struct in which the argument list and information about the flags, width
** precision and length are stored.
*/

typedef struct s_print
{
	va_list	ap;
	int		fd;
	int		i;
	int		ret;
	//int		len;
	int		check_neg;
	int		w_save;
	int		p_save;
	int		width;
	int		precision;
	int		hash;
	int		zero;
	int		space;
	int		upper;
	int		plus;
	int		minus;
	int		h;
	int		l;
	int		L;
	int		z;
	char	conv;
	char	*str;
}	t_print;

/*
** Main functions
*/

int	ft_printf(const char *format, ...);
int	ft_dprintf(int fd, const char *format, ...);
int	ft_asprintf(char **str, const char *format, ...);

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

static const t_able dispatch[13] = {
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
	NULL
};

/*
** ft_asprintf functions
*/

int		as_convert_yes(t_print *print, const char *format);
int		as_convert_no(t_print *print, const char *format);

/*
** ft_printf and ft_dprintf functions
*/

int		convert_yes(t_print *print, const char *format);
int		convert_no(t_print *print, const char *format);

/*
** Other functions
*/

void	free_struct(t_print *print);
void	init_struct(t_print *print);
void	str_reverse(char *str);
void	ft_strdel(char **as);
int		ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ll_len(long long n);
int		get_field(const char *format, t_print *print);
char	*ft_strcpy(char *dst, const char *src);
char	*zerostr(void);
char	*zeropad(char *str, int total, long long num);
char	*strnull(t_print *p, char *str);
char	*p_strnew(const char *format, int i);
char	*p_strjoin(char *str, const char *format, int i);
char	*strjoin_pro(char *str1, char *str2, int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_itoa_base(long long num, int base, t_print *print);
char	*ft_utoa_base(unsigned long long num, int base, t_print *print);
char	*insert_width(t_print *p, char *tmp, int free);
char	*insert_space_only(t_print *p, char *str);
long long signed_length_mod(t_print *p);
unsigned long long	unsigned_length_mod(t_print *p);

#endif
