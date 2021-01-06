/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:00:12 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/06 23:13:50 by mhogg            ###   ########.fr       */
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
	//printf("%.5d\n", 59);
	//ft_printf("hello %*.*d yes %%\n", 7, 0, 42);
	ft_printf("ft_printf: hello |%10.5d| yes\n", -42);
	printf("   printf: hello |%10.5d| yes\n", -42);
	ft_printf("ft_printf8.0d: |%8.0d|\n", 0); 
	printf("   printf8.0d: |%8.0d|\n", 0);   
	ft_printf("ft_printf8d:   |%.8d|\n", 0);  
	printf("   printf8d:   |%.8d|\n", 0); 
	// printf("--------------------------------------------start\n");
    // printf("this %d number\n", 0);
    // printf("%d\n", 0);
    // printf("%3d\n", 0);
    // printf("%.3d\n\n", 0);
    // printf("2-----------\n");
    // printf("%07d\n", -54);
    // printf("%03d\n", 0);
    // printf("%8.5d\n", 0);
    // printf("%.3d\n\n", 0);
    // printf("2-----------\n");
    // printf("%.0d\n", 0);
    // printf("%.d\n", 0);
    // printf("%5.0d\n", 0);
    // printf("%-5.0d\n", 0);
    // printf("%-5.d\n\n", 0);
    // printf("%07d\n", -54);
    // printf("%5.d\n", 1);
    // printf("%5.d\n", 0);
    // printf("%-5.d\n", 0);
    // printf("%.3d\n", 0);
    // printf("this %d number\n", 0);
    // printf("%.d\n", 0);
    // printf("%.0d\n", 0);;
    // printf("%05d\n", 43);
    // printf("%07d\n\n", -54);
    // printf("%03d\n\n", 0);
    // printf("%5d\n", 43);
    // printf("%7d\n", -54);
    // printf("%3d\n\n", 0);
    // printf("%0-8.5d", 34);
    // printf("%0.5d\n", 123);
    // printf("%5.10d\n", 123);
    // printf("%05.10d\n", 123);
    // printf("%-5.10d\n\n", 123);
    // printf("2-----------\n");
    // printf("%-10.5d\n", 123);
    // printf("%05.10d\n", -123);
    // printf("%-5.10d\n", -123);
    // printf("%010.5d\n\n", -123);
    // printf("3-----------\n");
    // printf("%05.10d\n", -123);
    // printf("%-5d\n", -123);
    // printf("%-10.5d\n", -123);
    // printf("%10.5d\n\n", -123);
    // printf("4-----------\n");
    // printf("%5.10d\n", -123);
    // printf("%10.5d\n", -123);
    // printf("%05.10d\n", -123);
    // printf("%-5.10d\n", -123);
    // printf("%-10.5d\n\n", -123);
    // printf("5-----------\n");
    // printf("%5.8d\n", -123456789);
    // printf("%8.5d\n", -123456789);
    // printf("%05.8d\n", -123456789);
    // printf("%-5.8d\n", -123456789);
    // printf("%-8.5d\n\n", -123456789);
    // printf("6-----------\n");
    // printf("%5.10d\n", -123456789);
    // printf("%10.5d\n", -123456789);
    // printf("%05.10d\n", -123456789);
    // printf("%-5.10d\n", -123456789);
    // printf("%-10.5d\n\n", -123456789);
    // printf("7-----------\n");
    // printf("%5.9d\n", -123456789);
    // printf("%9.5d\n", -123456789);
    // printf("%05.9d\n", -123456789);
    // printf("%-5.9d\n", -123456789);
    // printf("%-9.5d\n\n", -123456789);
    // printf("8-----------\n");
    // printf("%5.15d\n", -123456789);
    // printf("%15.5d\n", -123456789);
    // printf("%05.15d\n", -123456789);
    // printf("%-5.15d\n", -123456789);
    // printf("%-15.5d\n\n", -123456789);
    // printf("9-----------\n");
    // printf("%5.15d\n", 123456789);
    // printf("%15.5d\n", 123456789);
    // printf("%05.15d\n", 123456789);
    // printf("%-5.15d\n", 123456789);
    // printf("%-15.5d\n\n", 123456789);
    // printf("10-----------\n");
    // printf("%5.9d\n", 123456789);
    // printf("%9.5d\n", 123456789);
    // printf("%05.9d\n", 123456789);
    // printf("%-5.9d\n", 123456789);
    // printf("%-9.5d\n\n", 123456789);
    // printf("11-----------\n");
    // printf("%5.9d\n", -123456789);
    // printf("%9.5d\n", -123456789);
    // printf("%05.9d\n", -123456789);
    // printf("%-5.9d\n", -123456789);
    // printf("%-9.5d\n\n", -123456789);
    // printf("------------------------end");
}