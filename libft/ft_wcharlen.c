/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 20:55:46 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/20 20:57:04 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wcharlen(wchar_t c)
{
	int res;
	if (c <= 0x7F)
		res = 1;
	else if (c <= 0x7FF)
		res = 2;
	else if (c <= 0xFFFF)
		res = 3;
	else if (c <= 0x10FFFF)
		res = 4;
	return (res);
}