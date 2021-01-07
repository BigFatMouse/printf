/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:03:29 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/07 13:20:36 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct  s_arg
{
    int			len;
    int			width;
    int     	precision;
    char		flag;
    char    	type;
	int			nul;
}               t_arg;

int 	ft_printf(const char *str, ...);
void	ft_parser(const char **str, t_arg *param, va_list *args);
void	ft_pars_flag(const char **str, t_arg *param);
void	ft_processor(t_arg *param, va_list *args);
int		ft_atoi_move(const char **str);
void	ft_putnbr(int n, t_arg *param);
int		ft_numlen(int n);
void	ft_putchar(char c, t_arg *param);
void 	ft_print_d(int num, t_arg *param);
void	ft_print_d_part2(int num, int numlen, int nulls, t_arg *param);
void 	ft_print_c(char c, t_arg *param);

#endif
