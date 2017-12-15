/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:40:36 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/15 05:30:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_old_check_flags(const char c)
{
	if (c == 'c' || c == 'C')
		return (2);
	else if (c == 's' || c == 'S')
		return (3);
	else if (c  == 'd' || c == 'D' || c == 'i')
		return (4);
	else if (c == 'u' || c == 'U')
		return (5);
	else if (c == 'o' || c == 'O')
		return (6);
	else if (c  == 'x' || c == 'X')
		return (7);
	else if (c == 'p')
		return (8);
	else
		return (0);
}

void    ft_old_do_flag(const char *str, int check, va_list *vlist, size_t *len)
{
	(void)str;
	if (check == 2)
		ft_do_char(va_arg(*vlist, int), len);
	else if (check == 3)
		ft_do_str(va_arg(*vlist, char *), len);
	else if (check == 4)
		ft_do_int(va_arg(*vlist, int), len);
}
char	check_flag(va_list *vlist, t_printf *handler, char *str)
{

}

size_t	ft_do_flag(char **str, va_list *vlist)
{
	t_printf handler;
	if (**ptr == '%')
	{
		(*ptr)++;
		if (**ptr != '\0')
		{
			*ptr = check_flag(vlist, &handler, *str);
			return (printflag(vlist, &handler));
		}
	}
}
