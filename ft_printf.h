/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:03:29 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/12 19:38:50 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_arg
{
	int			len;
	int			width;
	int			precision;
	char		flag;
	char		type;
	int			minus;
	int			nul;
	int			error;
}				t_arg;

int				ft_printf(const char *str, ...);
void			ft_parser(const char **str, t_arg *param, va_list *args);
void			ft_processor(t_arg *param, va_list *args);
int				ft_atoi_move(const char **str);
void			ft_putnbr(unsigned num, unsigned base, t_arg *param);
int				ft_numlen(unsigned num, unsigned base);
void			ft_putchar(char c, t_arg *param);
void			ft_putstr(char *str, int strlen, t_arg *param);
int				ft_strlen(char *str);
void			ft_put_width(int numlen, t_arg *param);
void			ft_print_d(unsigned num, unsigned base, t_arg *param);
void			ft_print_d_part2(unsigned n, int len, int nulls, t_arg *param);
void			ft_print_s(char *str, t_arg *param);
void			ft_print_c(char c, t_arg *param);
void			ft_print_p(void *n, t_arg *param);
void			ft_print_p_part2(unsigned long long n, t_arg *param, int len);
#endif
