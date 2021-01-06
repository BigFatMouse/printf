# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct  s_arg
{
    int			len;
    int			width;
    int     	precision;
    char		flag;
    char    	type;
}               t_arg;

int		ft_atoi(const char **str)
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

void	ft_pars(const char *str, t_arg *params)
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
	params->width = ft_atoi(&str);
	if (*str == '.')
	{
		str++;
		// if (*str == '*')
		// {
		// 	//
		// }
		// else
			params->precision = ft_atoi(&str);
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
	
	ft_pars(str, &params);
	
	printf("flag [%c] width [%d] precison [%d] type [%c] \n", params.flag, params.width, params.precision, params.type);
	return (0);
}