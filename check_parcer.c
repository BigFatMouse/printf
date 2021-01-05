#include "ft_printf.h"

int	ft_atoi_move(const char **str)
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

void	ft_parser(const char *str, t_arg *params, va_list args)
{
	char	minus;

	params->flag = 0;
	params->width = 0;
	params->precision = 0;
	params->type = 0;

	while ((*str == '-' || *str == '0')) 
	{
		if (*str == '-')
			minus = '-';
		if (*str == '0')
			params->flag = '0';
		str++;
	}
	if (minus == '-')
		params->flag = '-';
	// if (*str == '*')
	// {
	// 	//
	// }
	// else
	printf("%s\n", str);
	params->width = ft_atoi_move(&str);
	if (*str == '.')
	{
		str++;
		// if (*str == '*')
		// {
		// 	//
		// }
		// else
			params->precision = ft_atoi_move(&str);
	}
	if (*str == 'd' || *str == 's' || *str == 'c' || *str == 'p' || *str == 'x' 
		|| *str == 'X' || *str == 'i' || *str == 'u' || *str == '%')
		params->type = *str;
}

int	main(void)
{
	t_arg params;
	
	params.flag = 0;
	params.width = 0;
	params.precision = 0;
	params.type = 0;
	
	const char *str = "000000-67.890d";
	
	ft_parser(str, &params);
	
	printf("flag [%c] width [%d] precison [%d] type [%c] \n", params.flag, params.width, params.precision, params.type);
	return (0);
}