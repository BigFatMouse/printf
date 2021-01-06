/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:00:12 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/06 13:38:05 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <unistd.h>
#include <stdarg.h>

int			ft_printf(const char *str, ...);

// int		main(void)
// {
// 	printf("Hello bois\n");
// 	ft_printf("Hello %% bois\n");
	
// 	printf("[%0.0d]\n", 50);
// 	printf("[%5.d]\n", 0);
// }

int	main(void)
{
	printf("%.5d\n", 59);
	ft_printf("hello %*.*d yes %%\n", 7, 0);
}