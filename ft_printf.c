/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:03:13 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/05 16:41:30 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <printf.h>


typedef		struct s_arg
{
	int len;
	int width;
	int precision;
	char type;
	char flag;
}					t_arg;

#pragma	region	parser

void		ft_printf_parser(const char *str, t_arg *ira)
{
	ira->width = 0;
	ira->precision = -1;
	ira->flag = '?';
	int i;
	
	i = 0;
	(void)str;
	// ira->width = ft_atoi(str[i + 1]);
	
	// while (str[i] != '.' || str[i])
	// {
	// 	if (str[i] == '.')
	// 		ira->precision = ft_atoi(str[i + 1]);
	// 	i++;
	// }
}

#pragma endregion parser



int			ft_printf(const char *str, ...)
{
	int i;
	va_list args;
	t_arg	ira;
	
	i = 0;
	ira.len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_printf_parser((char *)&str[i], &ira);
		}
		else
			ira.len += write(1, &str[i], 1);	
		i++;
	}
	va_end(args);
	printf("flag [%c] width [%d] precison [%d] type [%c] \n", ira.flag, ira.width, ira.precision, ira.type);
	return (ira.len);
}