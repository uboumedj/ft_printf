/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:48:59 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/15 04:36:56 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_do_int(int n, size_t *len)
{
	char *str;

	str = ft_itoa(n);
	ft_putstr(str);
	*len += ft_strlen(str);
}
