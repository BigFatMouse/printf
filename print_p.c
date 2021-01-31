/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:13:09 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/12 19:52:01 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_ptrlen(unsigned long long num)
{
	int	len;

	if (num == 0)
		return (3);
	len = 0;
	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len + 2);
}

void	ft_putnbr_hex(unsigned long long n, t_arg *param)
{
	int	a;

	if (param->nul == 1)
		return ;
	if (n < 16)
	{
		if (n < 10)
			a = n + 48;
		else
			a = n - 10 + 'a';
		ft_putchar(a, param);
	}
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, param);
		ft_putnbr_hex(n % 16, param);
	}
}

void	ft_putprefix(t_arg *param)
{
	ft_putstr("0x", 2, param);
}

void	ft_print_p(void *n, t_arg *param)
{
	int				numlen;
	unsigned long	num;

	if (n == NULL)
		num = 0;
	num = (unsigned long)n;
	numlen = ft_ptrlen(num);
	if (param->precision == 0 && n == NULL)
	{
		param->nul = 1;
		numlen = 2;
	}
	ft_print_p_part2(num, param, numlen);
}

void	ft_print_p_part2(unsigned long num, t_arg *param, int numlen)
{
	if (param->flag == '-')
	{
		ft_putprefix(param);
		ft_putnbr_hex(num, param);
		ft_put_width(numlen, param);
	}
	else	if (param->flag == '0')
	{
		ft_putprefix(param);
		ft_put_width(numlen, param);
		ft_putnbr_hex(num, param);
	}
	else
	{
		ft_put_width(numlen, param);
		ft_putprefix(param);
		ft_putnbr_hex(num, param);
	}
}
