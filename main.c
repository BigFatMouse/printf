/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 16:00:12 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/12 17:35:00 by mhogg            ###   ########.fr       */
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
	// ft_printf("ft_printf: hello |%10.5d| yes\n", -42);
	// printf("   printf: hello |%10.5d| yes\n", -42);
	// ft_printf("ft_printf8.0d: |%8.0d|\n", 0); 
	// printf("   printf8.0d: |%8.0d|\n", 0);   
	// ft_printf("ft_printf8d:   |%.8d|\n", 0);  
	// printf("   printf8d:   |%.8d|\n", 0); 
	
	//printf("-------------1st error-----------\n");
	// printf("%0-8.5d", 34);
    // printf("%0.5d\n", 123);
	// printf("   printf: |%0-8.5d|\n", 34);
	// ft_printf("ft_printf: |%0-8.5d|\n", 34);
    // printf("   printf: |%0.5d|\n", 123);
	// ft_printf("ft_printf: |%0.5d|\n", 123);
	
	// ft_printf("-------------2d error-----------\n");
	// // printf("%-10.5d\n", 123);
	// // printf("%05.10d\n", -123);
    // // printf("%-5.10d\n", -123);
    // // printf("%010.5d\n\n", -123);
	// printf("   printf: |%-10.5d|\n", 123);
	// ft_printf("ft_printf: |%-10.5d|\n", 123);
	// printf("   printf: |%05.10d|\n", -123);
	// ft_printf("ft_printf: |%05.10d|\n", -123);
	// printf("   printf: |%-5.10d|\n", -123);
	// ft_printf("ft_printf: |%-5.10d|\n", -123);
	// printf("   printf: |%010.5d|\n", -123);
	// ft_printf("ft_printf: |%010.5d|\n", -123);
	
	//printf("-------------3d error-----------\n");
	// // printf("%5.10d\n", -123456789);
    // // printf("%05.10d\n", -123456789);
    // // printf("%-5.10d\n", -123456789);
	// printf("   printf: |%5.6d|\n", -11111);
	// ft_printf("ft_printf: |%5.6d|\n", -11111);
	// printf("   printf: |%05.10d|\n", -123456789);
	// ft_printf("ft_printf: |%05.10d|\n", -123456789);
	// printf("   printf: |%-5.10d|\n", -123456789);
	// ft_printf("ft_printf: |%-5.10d|\n", -123456789);
	
//	printf("-------------4d error-----------\n");
	printf("   printf: |%8d|\n", 11111);
	ft_printf("ft_printf: |%8d|\n", 11111);
	//printf(1, -4, 9);
	ft_printf(NULL, -4, 9);
	
	int	num;
	char	c = 'c';
	char *ptr = &c;
	
	//printf("|%p, %*c|\n", ptr, 12, '-');
	//ft_printf("|%p, %*c|\n",  ptr, 12, '-');
	      
	// printf("printf:   |%20p|\n", ptr);
	// ft_printf("ft_printf:|%20p|\n\n", ptr);
	
	// printf("printf:   |%p|\n", ptr);
	// ft_printf("ft_printf:|%p|\n\n", ptr);
	
	// printf("printf:   |%0p|\n", NULL);
	// ft_printf("ft_printf:|%0p|\n\n", NULL);
	
	//printf(NULL);
	// ft_printf("|%2.9p|\n", 1234);
	// printf("|%2.9p|\n", 1234);
	
	// int a = -4;
	
	// printf("printf:   |%*p|, |%*p|\n", a, (void *)123, a, NULL);
	// ft_printf("ft_printf:|%*p|, |%*p|\n", a, (void *)123, a, NULL);
	// ft_printf("ft_printf:|%-4p|, |%-4p|\n", (void *)1, NULL);
}