/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:22:06 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/06 13:51:13 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_init(t_arg *param)
{
	param->len = 0;
	param->flag = 0;
	param->width = 0;
	param->precision = -1;
	param->type = 0;
}

int		ft_printf(const char *str, ...)
{
	t_arg	param;
	va_list args;

	ft_struct_init(&param);
	if (!str)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if ((*str == '%') && (*(++str) != '%'))
			ft_parser(&str, &param, &args);
		else
			param.len += write(1, str, 1);
		str++;
	}
	va_end(args);
	printf("flag [%c] width [%d] precison [%d] type [%c] len [%d]\n", param.flag, param.width, param.precision, param.type, param.len);
	return (param.len);
}

void	ft_parser(const char **str, t_arg *param, va_list *args)
{
	ft_pars_flag(str, param);
	if (**str == '*')
	{
		param->width = va_arg(*args, int);
		(*str)++;
	}
	else
		param->width = ft_atoi_move(str);
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			param->precision = va_arg(*args, int);
			(*str)++;
		}
		else
			param->precision = ft_atoi_move(str);
	}
	if (**str == 'd' || **str == 's' || **str == 'c'
		|| **str == 'p' || **str == 'x' || **str == 'X'
		|| **str == 'i' || **str == 'u' || **str == '%')
		param->type = **str;
}

void	ft_pars_flag(const char **str, t_arg *param)
{
	char	minus;

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
}

void	ft_processor(t_arg *param, va_list *args)
{
	if (param->type = 'd')
		ft_putnbr(va_arg(*args, int));
}

//ft_print_d()