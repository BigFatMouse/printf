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

void	ft_put_precision(unsigned num, int nulls, int base, t_arg *param)
{
	while (nulls--)
		ft_putchar('0', param);
	ft_putnbr(num, base, param);
}

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
	ft_print_d_part2(num, numlen, nulls, param);
}

void	ft_print_d_part2(unsigned num, int numlen, int nulls, t_arg *param)
{
	int	base;

	base = 10;
	if (param->type == 'x' || param->type == 'X')
		base = 16;
	if (param->flag == '-')
	{
		ft_put_minus(param);
		ft_put_precision(num, nulls, base, param);
		ft_put_width(numlen, param);
	}
	else	if (param->flag == '0')
	{
		ft_put_minus(param);
		ft_put_width(numlen, param);
		ft_put_precision(num, nulls, base, param);
	}
	else
	{
		ft_put_width(numlen, param);
		ft_put_minus(param);
		ft_put_precision(num, nulls, base, param);
	}
}
