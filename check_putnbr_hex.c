#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_hex(unsigned long num) //, t_arg *param)
{
	int	a;
	if (num < 16)
	{
		if (num < 10)
			a = num + 48;
		else
			a = num - 10  + 'a';
		write(1, &a, 1); //, param);
	}
	if (num >= 16)
	{
		ft_putnbr_hex(num / 16); //, param);
		ft_putnbr_hex(num % 16); //, param);
	}
}

void	ft_putnbr_hex2(unsigned long n)
{
	int	a;
	
	if (n < 16)
	{
		if (n < 10)
			a = n + 48;
		else
			a = n - 10 + 'a';
		write(1, &a, 1);
	}
	if (n > 16)
	{
		ft_putnbr_hex2(n / 16);
		ft_putnbr_hex2(n % 16);
	}
}

void	ft_putnbr(unsigned n, unsigned base) //, t_arg *param)
{
	int	a;
	int	toupper;
	
	toupper = 0;
	
	if (n < base)
	{
		if (n < 10)
		{
			a = n + 48;
			write(1, &a, 1);
		}
		if (n >= 10)
		{
			a = n - 10  + 'a' - toupper;
			write(1, &a, 1);
		}
	}	
	if (n >= base)
	{
		ft_putnbr(n / base, base); //, param);
		ft_putnbr(n % base, base); //, param);
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

void	ft_putptr(int num)
{
	int	len;
	int	a;
	int	n;
	int reg = 1;
	
	write(1, "0x", 2);
	len = ft_numlen(num);
	while (--len)
		reg *= 10;
	while(num > 10)
	{
		n = num/reg;
		a = n + 48;
		write(1, &a, 1);
		num = num - reg * n;
		reg = reg / 10;
	}
	a = num + 48;
	write(1, &a, 1);
}

int		ft_numlen_hex(unsigned long num)
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

void	ft_putptr_hex(unsigned long num)
{
	int			len;
	int			a;
	unsigned long	n;
	int 		reg;
	int 		base;
	
	base = 16;
	reg = 1;
	len = 8;
	write(1, "0x", 2);
	while (--len)
		reg *= base;
	while (num > base)
	{
		n = num/reg;
		if (n < 10)
			a = n + 48;
		else
			a = n - 10 + 'a';
		write(1, &a, 1);
		num = num - reg * n;
		reg = reg / base;
	}
	if (num < 10)
			a = num + 48;
	if (num >= 10)
			a = num - 10 + 97;
	write(1, &a, 1);
}

void	check_unsigned(int num)
{
	//unsigned long n;	
	unsigned	nu;
	
	// if (type == 'p')
	// 	p = num;
	// if (type == 'x')
	// 	x = num;
	if (num < 0)
		nu = -num;
	else
		nu = num;
	printf("%u\n", nu);
	n = num;
	printf("%lu\n", n);
}

int main(void)
{
	// int num = -123;
	// int *ptr = &num;
	// int **ptr2 = &ptr;
	// printf("%p\n", 69565501056);
	//ft_numlen_hex (ptr);
	// printf("\n");
	//check_unsigned(-2147483648);
	//printf("len = %d\n", ft_numlen_hex(num));
	//printf("\n");
	
	
	ft_putnbr_hex(-1);
	// printf("\n");
	// ft_putnbr_hex2(69565501056);
	// printf("\n");
	
}