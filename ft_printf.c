/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:22:06 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/12 01:27:14 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_init(t_arg *param)
{
	param->flag = 0;
	param->width = 0;
	param->precision = -1;
	param->type = 0;
	param->minus = 0;
	param->nul = 0;
	param->error = 0;
}

int		ft_printf(const char *str, ...)
{
	t_arg	param;
	va_list args;

	if (!str)
		return (-1);
	ft_struct_init(&param);
	param.len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_parser(&str, &param, &args);
			if (param.error == -1)
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
//	printf("flag [%c] width [%d] precison [%d] type [%c] len [%d]\n", param.flag, param.width, param.precision, param.type, param.len);
	va_end(args);
	return (param.len);
}

void	ft_parser(const char **str, t_arg *param, va_list *args)
{
	ft_pars_flag(str, param);
	if (**str == '*' && **str)
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
	if (**str == '.' && **str)
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
		param->error = -1;
}

void	ft_pars_flag(const char **str, t_arg *param)
{
	char	minus;

	if (**str == '\0')
		param->error = -1;
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
}
