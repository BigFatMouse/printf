/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhogg <mhogg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 21:03:29 by mhogg             #+#    #+#             */
/*   Updated: 2021/01/06 12:34:47 by mhogg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

int 	ft_printf(const char *str, ...);
void	ft_parser(const char **str, t_arg *param, va_list *args);
int		ft_atoi_move(const char **str);
void	ft_pars_flag(const char **str, t_arg *param);

#endif
