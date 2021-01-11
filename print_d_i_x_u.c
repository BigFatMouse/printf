/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i_x_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:24:18 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/12 01:28:37 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_minus(t_arg *param)
{
	if (param->minus == 1)
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

// void	ft_put_precision(int numlen, t_arg *param)
// {
// 	int	nulls;

// 	nulls = 0;
// 	if (param->precision > numlen)
// 		nulls = param->precision - numlen;
// 	while (nulls--)
// 		ft_putchar('0', param);
// }

void	ft_print_d(unsigned num, unsigned base, t_arg *param)
{
	int	numlen;
	int	nulls;

	nulls = 0;
	numlen = ft_numlen(num, base);
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
	if (param->minus == 1)
		numlen++;
	// printf("\n[numlen=%d]", numlen);
	// printf("[nulls=%d]\n", nulls);
	ft_print_d_part2(num, base, numlen, nulls, param);
}

void	ft_print_d_part2(unsigned num, unsigned base, int numlen, int nulls, t_arg *param)
{
	if (param->flag == '-')
	{
		ft_put_minus(param);
		ft_put_precision(nulls, param);
		ft_putnbr(num, base, param);
		ft_put_width(numlen, param);
	}
	else	if (param->flag == '0')
	{
		ft_put_minus(param);
		ft_put_width(numlen, param);
		ft_put_precision(nulls, param);
		ft_putnbr(num, base, param);
	}
	else
	{
		ft_put_width(numlen, param);
		ft_put_minus(param);
		ft_put_precision(nulls, param);
		ft_putnbr(num, base, param);
	}
}
