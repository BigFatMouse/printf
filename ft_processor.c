/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 00:24:32 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/12 00:57:51 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_d(t_arg *param, va_list *args)
{
	int				num;
	unsigned long	n;

	num = va_arg(*args, int);
	if (num < 0)
	{
		n = -num;
		param->minus = 1;
	}
	else
		n = num;
	ft_print_d(n, 10, param);
}

void	ft_processor(t_arg *param, va_list *args)
{
	char	*str;

	if (param->type == 'd' || param->type == 'i')
		ft_process_d(param, args);
	if (param->type == 'u')
		ft_print_d(va_arg(*args, unsigned), 10, param);
	if (param->type == 'x' || param->type == 'X')
	 	ft_print_d(va_arg(*args, unsigned), 16, param);
	if (param->type == 'p')
		ft_print_p(va_arg(*args, void *), param);
	if (param->type == 's')
	{
		if (!(str = va_arg(*args, char *)))
			str = "(null)";
		ft_print_s(str, param);
	}
	if (param->type == 'c')
		ft_print_c(va_arg(*args, int), param);
	if (param->type == '%')
		ft_print_c('%', param);
}
