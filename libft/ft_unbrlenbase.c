/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlenbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 20:47:46 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/02 14:01:18 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_unbrlenbase(unsigned long long int nb, unsigned int base)
{
	size_t		res;

	res = 1;
	while (nb >= base)
	{
		nb /= base;
		res++;
	}
	return (res);
}
