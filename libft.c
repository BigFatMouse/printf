#include "ft_printf.h"

void	ft_putchar(char c, t_arg *param)
{
	param->len += write(1, &c, 1);
}

int		ft_atoi_move(const char **str)
{
	int num;

	num = 0;
	if (**str == '\0')
		return (0);
	while (**str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	return (num);
}

int		ft_numlen(unsigned num, unsigned base)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num > 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}

void	ft_putnbr(unsigned num, unsigned base, t_arg *param)
{
	int	a;
	int	toupper;

	if (param->nul == 1)
		return ;
	toupper = 0;
	if (param->type == 'X')
		toupper = 32;
	if (num < base)
	{
		if (num < 10)
			a = num + 48;
		else
			a = num - 10 + 'a' - toupper;
		ft_putchar(a, param);
	}
	if (num >= base)
	{
		ft_putnbr(num / base, base, param);
		ft_putnbr(num % base, base, param);
	}
}

void	ft_putstr(char *str, int strlen, t_arg *param)
{
	if (str)
		while (strlen && *str)
		{
			ft_putchar(*str++, param);
			strlen--;
		}
}
