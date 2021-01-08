/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:24:18 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/09 02:18:20 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_minus(int minus, t_arg *param)
{
	if (minus == 1)
		ft_putchar('-', param);
}

void	ft_put_width(int numlen, t_arg *param)
{
	while (param->width > numlen)
	{
		if (param->flag == '0')
			ft_putchar('0', param);
		else
			ft_putchar(' ', param);
		numlen++;
	}
}

void	ft_put_precision(int nulls, t_arg *param)
{
	while (nulls--)
		ft_putchar('0', param);
}

void	ft_print_d(unsigned num, int minus, t_arg *param)
{
	int	numlen;
	int	nulls;

	numlen = ft_numlen(num);
	nulls = 0;
	if (num == 0 && param->precision == 0)
	{
		numlen--;
		param->nul = 1;
	}
	if ((param->precision >= 0) && (param->flag == '0'))
		param->flag = 0;
	if (param->precision > numlen)
	{
		nulls = param->precision - numlen;
		numlen = param->precision;
	}
	if (minus == 1)
		numlen++;
	ft_print_d_part2(num, minus, numlen, nulls, param);
}

void	ft_print_d_part2(unsigned num, int minus, int numlen, int nulls, t_arg *param)
{
	if (param->flag == '-')
	{
		ft_put_minus(minus, param);
		ft_put_precision(nulls, param);
		ft_putnbr(num, param);
		ft_put_width(numlen, param);
	}
	else	if (param->flag == '0')
	{
		ft_put_minus(minus, param);
		ft_put_width(numlen, param);
		ft_put_precision(nulls, param);
		ft_putnbr(num, param);
	}
	else
	{
		ft_put_width(numlen, param);
		ft_put_minus(minus, param);
		ft_put_precision(nulls, param);
		ft_putnbr(num, param);
	}
}

void	ft_print_s(char *str, t_arg *param)
{
	int	strlen;
	strlen = ft_strlen(str);
	
	if (param->precision >= 0 && param->precision < strlen)
	{
		strlen = param->precision;
	}
	if (param->flag == '-')
	{
		ft_putstr(str, strlen, param);
		ft_put_width(strlen, param);
	}
	else
	{
		ft_put_width(strlen, param);
		ft_putstr(str, strlen, param);
	}
}

void	ft_print_c(char c, t_arg *param)
{
	if (param->flag == '-')
	{
		ft_putchar(c, param);
		ft_put_width(1, param);
	}
	else
	{
		ft_put_width(1, param);
		ft_putchar(c, param);
	}
}

void	ft_print_x(unsigned num, t_arg param)
{
	
}
