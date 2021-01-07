/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:24:18 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/07 13:27:53 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_minus(int num, t_arg *param)
{
	if (num < 0)
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

void	ft_print_d(int num, t_arg *param)
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
	if (num < 0)
		numlen++;
	ft_print_d_part2(num, numlen, nulls, param);
}

void	ft_print_d_part2(int num, int numlen, int nulls, t_arg *param)
{
	if (param->flag == '-')
	{
		ft_put_minus(num, param);
		ft_put_precision(nulls, param);
		ft_putnbr(num, param);
		ft_put_width(numlen, param);
	}
	else	if (param->flag == '0')
	{
		ft_put_minus(num, param);
		ft_put_width(numlen, param);
		ft_put_precision(nulls, param);
		ft_putnbr(num, param);
	}
	else
	{
		ft_put_width(numlen, param);
		ft_put_minus(num, param);
		ft_put_precision(nulls, param);
		ft_putnbr(num, param);
	}
}
