#include <stdio.h>

int	ft_atoi(const char **str)
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

int	main(void)
{
	const char *str = "fghdjk";
	const char *str2 = str;
	
	int	num = ft_atoi(&str);
	printf("%d\n", num);
	printf("%d\n", str - str2);
	printf("%s\n", str);
}