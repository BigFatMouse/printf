#include "ft_printf.h"

void	ft_struct_init(t_arg *param)
{
	param->flag = 0;
	param->width = 0;
	param->precision = -1;
	param->type = 0;
	param->minus = 0;
	param->nul = 0;
}

int		ft_printf(const char *str, ...)
{
	t_arg	param;
	va_list args;

	if (!str)
		return (-1);
	param.len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(++str))
		{
			ft_parser(&str, &param, &args);
			if (param.len == -1)
			{
				va_end(args);
				return (-1);
			}
			ft_processor(&param, &args);
		}
		else
			ft_putchar(*str, &param);
		str++;
	}
	va_end(args);
	return (param.len);
}

void	ft_parser_part1(const char **str, t_arg *param, va_list *args)
{
	char	minus;

	minus = 0;
	ft_struct_init(param);
	while ((**str == '-' || **str == '0'))
	{
		if (**str == '-')
			minus = '-';
		if (**str == '0')
			param->flag = '0';
		(*str)++;
	}
	if (minus == '-')
		param->flag = '-';
	if (**str == '*')
	{
		if ((param->width = va_arg(*args, int)) < 0)
		{
			param->width = -(param->width);
			param->flag = '-';
		}
		(*str)++;
	}
	else
		param->width = ft_atoi_move(str);
}

void	ft_parser(const char **str, t_arg *param, va_list *args)
{
	ft_parser_part1(str, param, args);
	if (**str == '.')
	{
		if (*(++(*str)) == '*')
		{
			param->precision = va_arg(*args, int);
			(*str)++;
		}
		else
			param->precision = ft_atoi_move(str);
	}
	if (**str == 'd' || **str == 's' || **str == 'c' || **str == 'p' || **str
	== 'x' || **str == 'X' || **str == 'i' || **str == 'u' || **str == '%')
		param->type = **str;
	if (**str == '\0')
		param->len = -1;
}
