/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 20:22:06 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/06 00:24:07 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parser(const char **str, t_arg *params, va_list args)
{
	char	minus;

	params->flag = 0;
	params->width = 0;
	params->precision = 0;

	while ((**str == '-' || **str == '0')) 
	{
		if (**str == '-')
			minus = '-';
		if (**str == '0')
			params->flag = '0';
		(*str)++;
	}
	if (minus == '-')
		params->flag = '-';
	if (**str == '*')
	{
		params->width = va_arg(args, int);
		(*str)++;
	}
	else
		params->width = ft_atoi_move(str);
	if (**str == '.')
	{
		(*str)++;
		if (**str == '*')
		{
			params->precision = va_arg(args, int);
			(*str)++;
		}
		else
			params->precision = ft_atoi_move(str);
	}
	if (**str == 'd' || **str == 's' || **str == 'c' || **str == 'p' || **str == 'x' || **str == 'X' || **str == 'i' || **str == 'u' || **str == '%')
		params->type = **str;
}

int	ft_atoi_move(const char **str)
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

int ft_printf(const char *str, ...)
{
	t_arg	params;
	va_list args;

	params.len = 0;

	if (!str)
		return (-1);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%') // && *(str + 1) != '%'
		{
			str++;
			ft_parser(&str, &params, args);
		}
		else
		{
			params.len += write(1, str, 1);
		}
		str++;
	}
	va_end(args);
	printf("flag [%c] width [%d] precison [%d] type [%c] len [%d]\n", params.flag, params.width, params.precision, params.type, params.len);
	return (params.len);
}



int	main(void)
{
		ft_printf("hello %00-*.*d    yes \n", 7, 0);
}