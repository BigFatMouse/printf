/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:00:12 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/05 16:42:47 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <unistd.h>
#include <stdarg.h>

int			ft_printf(const char *str, ...);

int		main(void)
{
	printf("Hello bois\n");
	ft_printf("Hello %% bois\n");
	
	printf("[%0.0d]\n", 50);
	printf("[%5.d]\n", 0);
}