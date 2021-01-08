#include <stdio.h>
#include <unistd.h>

void	ft_putnbr_hex(unsigned num) //, t_arg *param)
{
	unsigned	a;
	if (num < 16)
	{
		if (num < 10)
			a = num + 48;
		else
			a = num - 10  + 'a' - 32;
		write(1, &a, 1); //, param);
	}
	if (num >= 16)
	{
		ft_putnbr_hex(num / 16); //, param);
		ft_putnbr_hex(num % 16); //, param);
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

void	check_unsigned(int num)
{
	unsigned long n;
	
	if (num < 0)
		n = -num;
	else
		n = num;
	printf("%lu\n", n);
}

int main(void)
{
	int num = 3849270;
	printf("%x\n", num);
	ft_putnbr_hex(num);
	printf("\n");
	//check_unsigned(-2147483648);
	printf("len = %d\n", ft_numlen_hex(num));
}