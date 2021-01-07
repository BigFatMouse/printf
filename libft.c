/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:14:05 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/07 15:59:39 by mhogg            ###   ########.fr       */
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

void	ft_putnbr(long num, t_arg *param)
{
	unsigned long	a;
	unsigned long	n;
	
	if (param->nul == 1)
		return ;
	if (num < 0 )
		num = -num;
	n = (unsigned long)num;
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

int		ft_numlen(long num)
{
	int 			len;
	unsigned long	n;
	
	if (num == 0)
		return (1);
	len = 0;
	if (num < 0)
		num = -num;
	n = (unsigned long)num;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

// int main(void)
// {
// 	printf("%d", ft_numlen(123));
// }