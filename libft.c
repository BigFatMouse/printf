/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:14:05 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/09 02:45:29 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_putnbr(unsigned n, t_arg *param)
{
	unsigned	a;
	
	if (param->nul == 1)
		return ;
	if (n <= 9)
	{
		a = n + 48;
		ft_putchar(a, param);
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, param);
		ft_putnbr(n % 10, param);
	}
}

int		ft_numlen(unsigned num)
{
	int 		len;
	
	if (num == 0)
		return (1);
	len = 0;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_hex(unsigned num, t_arg *param)
{
	unsigned	a;
	int			toupper;
	
	if (param->nul == 1)
		return ;
	toupper = 0;
	if (param->type == 'X')
		toupper = 32;
	if (num < 16)
	{
		if (num < 10)
			a = num + 48;
		else
			a = num - 10  + 'a' - toupper;
		ft_putchar(a, param);
	}
	if (num >= 16)
	{
		ft_putnbr_hex(num / 16, param);
		ft_putnbr_hex(num % 16, param);
	}
}

int		ft_numlen_hex(unsigned num)
{
	int 		len;
	
	if (num == 0)
		return (1);
	len = 0;
	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
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

int		ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// int main(void)
// {
// 	int len = ft_strlen("hello");
// 	printf("%d", len);
// }